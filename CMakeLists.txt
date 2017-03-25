cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)

add_library(commandline STATIC src/commandline/CommandLine.cpp)
target_include_directories(commandline
	PRIVATE src
	PUBLIC include)
