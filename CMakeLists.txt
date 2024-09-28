cmake_minimum_required(VERSION 3.10)
project(SNAKE_CPP)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for headers
include_directories(include)

# Add the ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add the executable and the source files
add_executable(snake
    src/main.cpp
    src/console.cpp
)

# Link the ncurses library to the project
target_link_libraries(snake ${CURSES_LIBRARIES})
