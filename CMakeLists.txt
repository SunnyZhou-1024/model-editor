cmake_minimum_required(VERSION 3.5)

project(model_editor VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

set(REPO_ROOT ${PROJECT_SOURCE_DIR})
set(SRC_DIR ${REPO_ROOT}/src)
set(INCLUDE_DIR ${REPO_ROOT}/include)
set(REPO_BUILD_DIR ${REPO_ROOT}/build)

add_subdirectory(${REPO_ROOT}/third_party/protobuf/cmake EXCLUDE_FROM_ALL)

set(PROTOBUF_PROTOC_EXECUTABLE ${REPO_ROOT}/build/third_party/protobuf/cmake/protoc)

message(STATUS ${PROTOBUF_PROTOC_EXECUTABLE})
list(APPEND PROTO_FILES 
     #"${REPO_ROOT}/protobuf/onnx.in.proto"
     #"${REPO_ROOT}/protobuf/onnx-operators.in.proto"
     "${REPO_ROOT}/protobuf/onnx-operators-ml.proto"
     "${REPO_ROOT}/protobuf/onnx-ml.proto"
     #"${REPO_ROOT}/protobuf/onnx-data.in.proto"
     )

set(output_dir ${REPO_ROOT}/include)
set(protoc_include ${REPO_ROOT}/protobuf)

foreach(fil ${PROTO_FILES})
    get_filename_component(abs_fil ${fil} ABSOLUTE)
    get_filename_component(fil_we ${fil} NAME_WE)

    list(APPEND ${srcs_var} "${output_dir}/${fil_we}.pb.cc")
    list(APPEND ${hdrs_var} "${output_dir}/${fil_we}.pb.h")

    add_custom_command(
        OUTPUT "${output_dir}/${fil_we}.pb.cc"
                "${output_dir}/${fil_we}.pb.h"
        COMMAND ${PROTOBUF_PROTOC_EXECUTABLE} --cpp_out    ${output_dir} -I${protoc_include} ${abs_fil}
        DEPENDS ${abs_file}
        COMMENT "Running C++ protocol buffer compiler on ${fil}" VERBATIM )


    message(STATUS "Compile ${fil_we}")
endforeach()

# add_subdirectory(${REPO_ROOT}/third_party/onnx EXCLUDE_FROM_ALL)

list(APPEND CXX_SRCS ${REPO_ROOT}/src/model-editor.cpp
     ${REPO_ROOT}/src/models.cpp
     ${REPO_ROOT}/include/onnx-ml.pb.cc)
add_executable(model_editor ${CXX_SRCS})

target_include_directories(model_editor PUBLIC ${REPO_ROOT}/include)
target_include_directories(model_editor PUBLIC ${REPO_ROOT}/third_party/protobuf/src)
target_link_libraries(model_editor PUBLIC ${REPO_BUILD_DIR}/third_party/protobuf/cmake/libprotobuf.a)
target_link_libraries(model_editor PUBLIC pthread)



