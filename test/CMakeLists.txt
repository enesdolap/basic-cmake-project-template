cmake_minimum_required(VERSION 3.15...3.23)

project(CmakeConfigPackageTests LANGUAGES CXX)

find_package(GTest REQUIRED)

add_subdirectory(example_test)
#add_subdirectory(new_package)