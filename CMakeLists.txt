cmake_minimum_required(VERSION 2.8.9)
project (gridworld)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

include_directories(include)

add_executable(exec src/main.cpp src/gridworld.cpp)

