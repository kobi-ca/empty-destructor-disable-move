cmake_minimum_required(VERSION 3.21)
project(empty_destructor_disable_move)

set(CMAKE_CXX_STANDARD 23)

add_executable(empty_destructor_disable_move main.cpp utils.cpp utils.hpp)
add_executable(cppref_move_ctor cppreference-move-constructor.cpp)
add_executable(detect detect.cpp)
