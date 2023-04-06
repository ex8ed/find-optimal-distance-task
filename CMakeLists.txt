cmake_minimum_required(VERSION 3.20)
project(lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab main.cpp Command.cpp Command.h Container.cpp Container.h)
