cmake_minimum_required(VERSION 3.1.0)
project(basis)
add_executable(basis test.cpp)
target_compile_features(basis PRIVATE cxx_range_for)
