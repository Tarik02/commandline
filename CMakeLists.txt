add_library(commandline STATIC src/commandline/CommandLine.cpp)
target_include_directories(commandline
	PRIVATE src
	PUBLIC include)
