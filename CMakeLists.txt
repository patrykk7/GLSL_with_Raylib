cmake_minimum_required(VERSION 4.0)
project(GLSL_introduction)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        raylib URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
)
FetchContent_MakeAvailable(raylib)

add_executable(GLSL_introduction
        main.cpp
        shaders/vertex_shader.vert
        shaders/fragment_shader.frag
)

target_link_libraries(GLSL_introduction PRIVATE raylib)
