cmake_minimum_required(VERSION 3.5)

project(model_editor VERSION 0.0.1 LANGUAGES CXX)

set(REPO_ROOT ${PROJECT_SOURCE_DIR})
list(APPEND CXX_SRCS ${REPO_ROOT}/src/model-editor.cpp)
add_executable(model_editor ${CXX_SRCS})

target_include_directories(model_editor PUBLIC ${REPO_ROOT}/include)

