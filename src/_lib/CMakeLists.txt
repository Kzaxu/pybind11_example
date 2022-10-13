cmake_minimum_required(VERSION 3.19)
project(_lib)

set(pybind11_path D:\\ProgramData\\Anaconda3\\Lib\\site-packages\\pybind11)
find_package(pybind11 CONFIG REQUIRED PATHS ${pybind11_path})

add_library(${PROJECT_NAME} vector_api.cpp)
target_link_libraries(_lib PRIVATE pybind11::module pybind11::lto pybind11::windows_extras pybind11::embed)
target_include_directories(${PROJECT_NAME} PUBLIC  .)