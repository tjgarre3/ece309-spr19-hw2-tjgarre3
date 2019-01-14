cmake_minimum_required(VERSION 3.13)
project(hw2)

set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_CXX_STANDARD 11)

add_executable(list LinkedList.cpp)
add_executable(alist ArrayList.cpp)