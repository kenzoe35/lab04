macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})

    target_link_libraries(${TESTNAME} PRIVATE library GTest::gtest_main)

    gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURE_DIR}"
    )

    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

#package_add_test(test_name test_file.cpp)
package_add_test(test_grading test_grading.cpp)
