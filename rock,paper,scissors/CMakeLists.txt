cmake_minimum_required(VERSION 3.15.3)
project(RockPaperScissors)

set(CMAKE_CXX_STANDARD 11)

add_executable(RockPaperScissors main.cpp inputvalidation.cpp game.cpp game.h inputvalidation.h)
