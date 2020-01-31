### This file is used for build example projects.

# set this will supress some warnings
set(BUILDING_SDK "yes" CACHE INTERNAL "")


# basic config
if (NOT PROJ)
    get_filename_component(PROJ ${CMAKE_CURRENT_BINARY_DIR} DIRECTORY)
    get_filename_component(PROJ ${PROJ} NAME)
    string(REPLACE " " "_" PROJ ${PROJ})
    message(STATUS "PROJ not set, use ${PROJ} as PROJ. Also, you can set it manually. e.g. -DPROJ=hello_world")
else()
    message("PROJ = ${PROJ}")
endif ()
cmake_minimum_required(VERSION 3.0)
include(./cmake/common.cmake)
project(${PROJ} C CXX ASM)

# config self use headers
include(./cmake/macros.internal.cmake)
header_directories(${SDK_ROOT}/lib)
header_directories(${SDK_ROOT}/components)

#header_directories(src/${PROJ})
#header_directories(kendryte-standalone-demo/${PROJ})
include_directories(src/micro/tensorflow)
#header_directories(src/micro/tensorflow/tensorflow/lite/micro)
include_directories(src/micro/tensorflow/tensorflow/lite/micro/tools/make/downloads)
include_directories(src/micro/tensorflow/tensorflow/lite/micro/tools/make/downloads/gemmlowp)
include_directories(src/micro/tensorflow/tensorflow/lite/micro/tools/make/downloads/flatbuffers/include)
include_directories(src/micro/tensorflow/tensorflow/lite/micro/tools/make/downloads/flatbuffers/include)

# build library first
add_subdirectory(lib)


add_compile_definitions(TF_LITE_USE_GLOBAL_ROUND)

# compile project
add_source_files(src/micro/tensorflow/tensorflow/lite/micro/*.cc)
add_source_files(src/micro/tensorflow/tensorflow/lite/micro/kernels/*.cc)
add_source_files(src/micro/tensorflow/tensorflow/lite/micro/memory_planner/*.cc)
add_source_files(src/micro/tensorflow/tensorflow/lite/c/common.c)
add_source_files(src/micro/tensorflow/tensorflow/lite/core/api/error_reporter.cc)
add_source_files(src/micro/tensorflow/tensorflow/lite/core/api/flatbuffer_conversions.cc)
add_source_files(src/micro/tensorflow/tensorflow/lite/core/api/op_resolver.cc)
add_source_files(src/micro/tensorflow/tensorflow/lite/core/api/tensor_utils.cc)
add_source_files(src/micro/tensorflow/tensorflow/lite/kernels/internal/quantization_util.cc)
add_source_files(src/micro/tensorflow/tensorflow/lite/kernels/kernel_util.cc)
add_source_files(src/micro/tensorflowtensorflow/lite/micro/examples/hello_world/main.cc)
add_source_files(src/micro/tensorflowtensorflow/lite/micro/examples/hello_world/main_functions.cc)
add_source_files(src/micro/tensorflowtensorflow/lite/micro/examples/hello_world/sine_model_data.cc)
add_source_files(src/micro/tensorflowtensorflow/lite/micro/examples/hello_world/output_handler.cc)
add_source_files(src/micro/tensorflowtensorflow/lite/micro/examples/hello_world/constants.cc)
add_source_files(src/micro/tensorflowtensorflow/lite/micro/riscv64_mcu/*.cc)

add_source_files(kendryte-standalone-demo/${PROJ}/*.c kendryte-standalone-demo/${PROJ}/*.s kendryte-standalone-demo/${PROJ}/*.S kendryte-standalone-demo/${PROJ}/*.cpp)
include(./cmake/executable.cmake)

