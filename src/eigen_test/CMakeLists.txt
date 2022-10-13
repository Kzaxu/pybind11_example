cmake_minimum_required(VERSION 3.19)

project(eigen_test LANGUAGES CXX)

# pybind11 cmake config 路径
set(pybind11_DIR D:/ProgramData/Anaconda3/Lib/site-packages/pybind11/share/cmake/pybind11)
find_package(pybind11 REQUIRED) 

# eigen3 cmake 路径
set(Eigen3_DIR D:/ProgramData/CppLib/share/eigen3/cmake)
find_package(Eigen3 REQUIRED)

set(LINK_THIRD_LIBS
    Eigen3::Eigen 
    pybind11::module 
    pybind11::lto 
    pybind11::windows_extras)

add_library(${PROJECT_NAME} eigen_api.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LINK_THIRD_LIBS} pybind11::embed)

pybind11_add_module(eigen_api eigen_api.cpp)
target_link_libraries(eigen_api PRIVATE ${LINK_THIRD_LIBS})
set_target_properties(eigen_api
    PROPERTIES 
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
if (MSVC)
    foreach(OUTPUTCFG ${CMAKE_CONFIGURATION_TYPES})
        string( TOUPPER ${OUTPUTCFG} OUTPUTCFG )
        set_target_properties(eigen_api
            PROPERTIES 
            LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCFG} ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endforeach(OUTPUTCFG ${CMAKE_CONFIGURATION_TYPES})
endif(MSVC)

