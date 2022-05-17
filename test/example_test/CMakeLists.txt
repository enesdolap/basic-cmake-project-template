cmake_minimum_required(VERSION 3.15...3.23)

# Provide a simple smoke test to make sure that the CLI works and can display a --help message
add_test(NAME cli.has_help COMMAND intro --help)
add_test(NAME cli.version_matches COMMAND intro --version)
set_tests_properties(cli.version_matches PROPERTIES PASS_REGULAR_EXPRESSION "${PROJECT_VERSION}")

file(GLOB_RECURSE EXAMPLE_PKG_SOURCES CONFIGURE_DEPENEDS "${CMAKE_SOURCE_DIR}/src/example/*.cpp")
file(GLOB_RECURSE EXAMPLE_PKG_TEST_SOURCES CONFIGURE_DEPENEDS "./*.cpp")

set(ALL_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/src/")

add_executable(example_tests "${EXAMPLE_PKG_SOURCES}" "${EXAMPLE_PKG_TEST_SOURCES}")

target_link_libraries(example_tests PUBLIC GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
target_link_libraries(example_tests PRIVATE myproject::project_warnings myproject::project_options)

target_include_directories(example_tests PUBLIC "${ALL_INCLUDE_DIRS}")

gtest_discover_tests(example_tests)
