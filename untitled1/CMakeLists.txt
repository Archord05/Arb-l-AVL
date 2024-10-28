cmake_minimum_required(VERSION 3.29)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        Model/Arbol.cpp
        Model/Arbol.h
        Model/Nodo.cpp
        Model/Nodo.h
)
