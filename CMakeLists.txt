cmake_minimum_required(VERSION 3.27)
project(Top_1000_Albums)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Top_1000_Albums
        Album.h
        main.cpp)
