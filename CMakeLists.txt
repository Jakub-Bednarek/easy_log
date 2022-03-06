cmake_minimum_required(VERSION 3.0.0)
project(EasyLog)

set(HEADER_FILES 
        src/EasyLog.hpp
)

set(SOURCE_FILES
        src/main.cpp        
)

add_executable(EasyLog ${HEADER_FILES} ${SOURCE_FILES})