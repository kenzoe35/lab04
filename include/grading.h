// include/grading.h
#ifndef GRADING_H
#define GRADING_H

#include "constants.h"

/**
 * @brief Calculates one student's mean score across all assignments.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores        The grade grid.
 * @param[in] studentIndex  Row of the student to average.
 * @return The mean of that student's assignment scores.
 */
[[nodiscard]] double studentAverage(const ScoreGrid& scores,
                                    int studentIndex);

/**
 * @brief Calculates the mean score on one assignment across all students.
 *
 * @pre assignmentIndex is in the range [0, ASSIGNMENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores           The grade grid.
 * @param[in] assignmentIndex  Column of the assignment to average.
 * @return The mean score earned on that assignment.
 */
[[nodiscard]] double assignmentAverage(const ScoreGrid& scores,
                                       int assignmentIndex);

/**
 * @brief Calculates the mean of every score in the grid.
 *
 * @post The scores grid is not modified.
 *
 * @param[in] scores  The grade grid.
 * @return The mean of all STUDENT_COUNT * ASSIGNMENT_COUNT scores.
 */
[[nodiscard]] double classAverage(const ScoreGrid& scores);

/**
 * @brief Finds one student's lowest and highest assignment scores.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post lowest holds that student's minimum score.
 * @post highest holds that student's maximum score.
 * @post The scores grid is not modified.
 *
 * @param[in]  scores        The grade grid.
 * @param[in]  studentIndex  Row of the student to examine.
 * @param[out] lowest        Receives the minimum score.
 * @param[out] highest       Receives the maximum score.
 */
void findExtremes(const ScoreGrid& scores, int studentIndex,
                  double& lowest, double& highest);

/**
 * @brief Counts how many students earned a given letter grade.
 *
 * @pre target is one of 'A', 'B', 'C', 'D', or 'F'.
 * @post The scores grid is not modified.
 *
 * @param[in] scores  The grade grid.
 * @param[in] target  The letter grade to count.
 * @return The number of students whose average earns that letter.
 */
[[nodiscard]] int countGrade(const ScoreGrid& scores, char target);

/**
 * @brief Reports whether a student earned a perfect score on any assignment.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores        The grade grid.
 * @param[in] studentIndex  Row of the student to examine.
 * @return true if any of that student's scores is 100 or above.
 */
[[nodiscard]] bool hasPerfectScore(const ScoreGrid& scores,
                                   int studentIndex);

/**
 * @brief Reports whether a student is academically at risk.
 *
 * A student is at risk when their average is below 70, or when any
 * single assignment score is below 50.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores        The grade grid.
 * @param[in] studentIndex  Row of the student to examine.
 * @return true if either at-risk condition holds.
 */
[[nodiscard]] bool isAtRisk(const ScoreGrid& scores, int studentIndex);

/**
 * @brief Counts the amount of students that are at risk
 *
 * @pre studentIndex is in range [0, STUDENT_COUNT).
 * @post The number of students at risk
 *
 * @param[in] scores        The grade grid.
 * @param[in] studentIndex  Row of the student to examine.
 * @return the integer of students at risk
 */
[[nodiscard]] int countAtRisk(const ScoreGrid& scores, int studentIndex);

/**
 * @brief Finds the lowest and highest grades along with the student
 *
 * @pre Assignment count is greater than 0
 * @post Finds the highest and lowest grades
 *
 * @param[in] scores        The grade grid.
 * @param[in] lowest        The grade recorded.
 * @param[in] highest       The highest grade recorded.
 * @param[in] lowestStudent The student with the lowest grade
 * @param[in] highestStudent The student with the highest grade
 */
void findClassExtremes(const ScoreGrid& scores, double& lowest, double& highest, int& lowestStudent, int& highestStudent);
/**
 * @brief Adds an extra 5 points for every student's grade
 *
 * @pre Student average is less than 100
 * @post Adds 5 to the student average with a max cap of 100
 *
 * @param[in] scores        The grade grid.
 *
 */
void applyCurve(const ScoreGrid& scores);

/**
 * @brief Finds the student that has the highest average
 *
 * @pre Has to be the highest average student
 * @post Prints the row of the student with the highest average
 *
 * @param[in] scores        The grade grid.
 * @return the row of the student with the highest grade
 */
[[nodiscard]] int topStudent(const ScoreGrid& scores);

#endif
