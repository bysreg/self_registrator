cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(self_register)

set(CMAKE_CXX_STANDARD 11) # use c++11

######## CREATE EACH TARGET ##########

file(GLOB REGISTER_FILES
	"object.hpp"
	"define.hpp"
	"derived_object.hpp"
	"derived_object.cpp"
)
add_library(register_target ${REGISTER_FILES})
set_target_properties(register_target PROPERTIES COMPILE_FLAGS "${PROGRAM_COMPILE_FLAGS}" LINKER_LANGUAGE CXX)


# add target test
file(GLOB TEST_FILES
	"main.cpp"
)

add_executable(main_target ${TEST_FILES})
set_target_properties(main_target PROPERTIES COMPILE_FLAGS "${PROGRAM_COMPILE_FLAGS} ")
target_link_libraries(main_target register_target)
#======================================
