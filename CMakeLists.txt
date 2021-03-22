cmake_minimum_required(VERSION 3.15)
project(MediaConvertor)

file(GLOB_RECURSE source "s/*.cpp" "s/*.h")

add_executable(${PROJECT_NAME} ${source})