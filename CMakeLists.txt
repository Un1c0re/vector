cmake_minimum_required(VERSION 3.21)
project(vector)

set(CMAKE_CXX_STANDARD 23)

add_executable(vector vector.cpp vector.h list.cpp list.h main.cpp)
