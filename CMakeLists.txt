cmake_minimum_required(VERSION 3.21)
project(ocarn2)

set(CMAKE_C_STANDARD 17)

include_directories(.)


add_executable(example_3df example_3df.cpp)
add_executable(example_car example_car.cpp)
add_executable(example_rsc example_rsc.cpp)
add_executable(example_map example_map.cpp)