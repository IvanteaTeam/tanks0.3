cmake_minimum_required(VERSION 3.20)

project(tanks)

add_executable(tanks WIN32 main.cpp)

target_link_libraries(tanks PUBLIC winmm.lib)

