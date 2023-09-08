cmake_minimum_required(VERSION 3.26)
project(pruebatest)

set(BINARY_DIR "${CMAKE_BINARY_DIR}/bin")

add_executable(pruebatest main.cpp)

add_subdirectory("C:/Users/User/Downloads/googletest-main" ${BINARY_DIR})

target_link_libraries(pruebatest gtest)
