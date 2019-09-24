cmake_minimum_required(VERSION 3.10.2)

project(Pass-By-Reference-Test)

# Python file must be along side the example executable
file(COPY "src/example.py" DESTINATION "${CMAKE_BINARY_DIR}")

add_subdirectory(lib/pybind11)

add_executable(example src/example.cpp)
target_link_libraries(example PRIVATE pthread pybind11::embed -lpthread)
