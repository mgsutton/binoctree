cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.13)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
	cmake_policy(VERSION 3.14)
endif()

project(binOctree VERSION 1.0
	              DESCRIPTION "A C++ binarized octree datastructure."
	              LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/catch)
add_library(Catch2::Catch IMPORTED INTERFACE)
set_property(TARGET Catch2::Catch PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CATCH_INCLUDE_DIR}")

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

# Packages
find_package(Eigen3 REQUIRED)
if(NOT EIGEN3_FOUND)
	message(FATAL_ERROR "Could not find the eigen libraries...")
endif()


# Bring in the header only library for the
# octree

set(octreeHeaders
	${CMAKE_SOURCE_DIR}/include/padt/octree/octree.h)

add_library(binOctree INTERFACE)
target_sources(binOctree INTERFACE ${octreeHeaders})
target_include_directories(binOctree INTERFACE "include/padt/octree")
target_include_directories(binOctree INTERFACE ${EIGEN3_INCLUDE_DIR})