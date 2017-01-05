# cmake_minimum_required(VERSION <specify CMake version here>)
project(funPalindrome)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Main.cpp Print.h Builder.cpp Builder.h)
add_executable(funPalindrome ${SOURCE_FILES})