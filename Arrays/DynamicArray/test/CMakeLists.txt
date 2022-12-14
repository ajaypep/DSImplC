cmake_minimum_required(VERSION 3.20)

include(FetchContent)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(gtest)

enable_testing()

add_executable(io_tests io_tests.c)
add_executable(
        non_io_tests
        insertion_tests.cpp
)
target_link_libraries(
        non_io_tests PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(non_io_tests)

if (MSVC)
    target_compile_options(non_io_tests PRIVATE)
else()
    target_compile_options(non_io_tests PRIVATE)
endif()