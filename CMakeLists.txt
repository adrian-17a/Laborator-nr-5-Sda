cmake_minimum_required(VERSION 3.29)
project(lab5sda C)

set(CMAKE_C_STANDARD 11)

add_library(lab5sda STATIC library.c
        main.c
        algorithms.c
        algorithms.h
)
