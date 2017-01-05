# cmake_minimum_required(VERSION <specify CMake version here>)
project(test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Main.cpp)
add_executable(test ${SOURCE_FILES})