// src/grading.cpp
#include "grading.h"

#include <algorithm>

#include "utilities.h"

double studentAverage(const ScoreGrid& scores, int studentIndex) {
    double total{};

    // Total the assignment scores for this student
    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) {
        total += scores[studentIndex][i];
    }

    return total / ASSIGNMENT_COUNT;
}

double assignmentAverage(const ScoreGrid& scores, int assignmentIndex) {
    double total{};

    // Total this assignment's score down every student row
    for (auto i{0}; i < STUDENT_COUNT; i++) {
        total += scores[i][assignmentIndex];
    }

    return total / STUDENT_COUNT;
}

double classAverage(const ScoreGrid& scores) {
    double total{};

    for (auto i{0}; i < STUDENT_COUNT; i++) {
        for (auto j{0}; j < ASSIGNMENT_COUNT; j++) {
            total += scores[i][j];
        }
    }

    return total / (STUDENT_COUNT * ASSIGNMENT_COUNT);
}

void findExtremes(const ScoreGrid& scores, int studentIndex,
                  double& lowest, double& highest) {
    // Start from a real score so the result is correct for any range of
    // values, including all-negative ones
    lowest = scores[studentIndex][0];
    highest = scores[studentIndex][0];

    for (auto i{1}; i < ASSIGNMENT_COUNT; i++) {
        lowest = std::min(lowest, scores[studentIndex][i]);
        highest = std::max(highest, scores[studentIndex][i]);
    }
}

int countGrade(const ScoreGrid& scores, char target) {
    int count{};

    for (auto i{0}; i < STUDENT_COUNT; i++) {
        if (letterGrade(studentAverage(scores, i)) == target) {
            count++;
        }
    }

    return count;
}

bool hasPerfectScore(const ScoreGrid& scores, int studentIndex) {
    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) {
        if (scores[studentIndex][i] >= 100.0) {
            return true;
        }
    }

    return false;
}

bool isAtRisk(const ScoreGrid& scores, int studentIndex) {
    if (studentAverage(scores, studentIndex) < 70.0) {
        return true;
    }

    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) {
        if (scores[studentIndex][i] < 50.0) {
            return true;
        }
    }

    return false;
}

int countAtRisk(const ScoreGrid& scores, int studentIndex) {

    int count = 0;
    
    for (for i = 0; i < STUDENT_COUNT; i++) {
        if (isAtRisk(scores, i)) {
            count++;
        }
    }
    return count;
}


void findClassExtremes(const ScoreGrid& scores, double& lowest, double& highest, int& lowestStudent, int& highestStudent) {
    lowest = scores[0][0];
    highest = scores[0][0];
    lowestStudent = 0;
    highestStudent = 0;

    for (int i = 0; i < STUDENT_COUNT; i++ {
        for (int j = 0; j < ASSIGNMENT_COUNT; j++) {
           if (scores[i][j] < lowest) {
            lowest = scores[i][j];
            lowestStudent = i;
           }
           if (scores[i][j] > highest) {
            highest = scores[i][j];
            highestStudent = i;
           }
        }
    }    
}

void applyCurve(ScoreGrid& scores) {
    for (int i = 0; i < STUDENT_COUNT; i++) {
        for (int j = 0; j < ASSIGNMENT_COUNT; j++) {
            scores [i][j] += 5.0;
            
            if (scores[i][j] > 100.0) {
                scores[i][j] = 100.0;
            }
        }
    }    
}

int topStudent(const ScoreGrid& scores) {
    int topIndex = 0;
    double highestAverage = studentAverage(scores, 0);
    
    for (int i = 0; i < STUDENT_COUNT; i++) {
        double currentAverage = studentAverage(scores, i);
        if (currentAverage > highestAverage) {
            highestAverage = currentAverage;
            topIndex = i;
        }
        
    }
    return topIndex;
}
