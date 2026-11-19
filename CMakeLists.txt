cmake_minimum_required(VERSION 3.20)

project(harness LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find external dependencies
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

# Executable
add_executable(harness
    src/main.cpp
    src/envelope.cpp
)

# Header directories
target_include_directories(harness PRIVATE
    include
)

# Link external dependencies
target_link_libraries(harness PRIVATE
    OpenGL::GL
    SDL2::SDL2
)

# Compiler warnings
target_compile_options(harness PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)