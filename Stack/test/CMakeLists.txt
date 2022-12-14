cmake_minimum_required(VERSION 3.20)

include(FetchContent)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(gtest)

enable_testing()

add_executable(run_io_tests io_tests.c)
add_executable(
        run_non_io_tests
        push_tests.cpp
)
target_link_libraries(
        run_non_io_tests PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_non_io_tests)

if (MSVC)
    target_compile_options(run_io_tests PRIVATE /W4 /WX)
else()
    target_compile_options(run_io_tests PRIVATE -Wall -Wextra -pedantic -Werror )
endif()