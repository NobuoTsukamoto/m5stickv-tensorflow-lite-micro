#project(components)

# create driver library
message("CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")

FILE(GLOB_RECURSE LIB_SRC
        "${CMAKE_CURRENT_LIST_DIR}/*.h"
        "${CMAKE_CURRENT_LIST_DIR}/*.hpp"
        "${CMAKE_CURRENT_LIST_DIR}/*.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/*.s"
        "${CMAKE_CURRENT_LIST_DIR}/*.S"
        )

message("LIB_SRC: ${LIB_SRC}")

FILE(GLOB_RECURSE ASSEMBLY_FILES
        "${CMAKE_CURRENT_LIST_DIR}/*.s"
        "${CMAKE_CURRENT_LIST_DIR}/*.S"
        )

include_directories(${CMAKE_CURRENT_LIST_DIR}/boards/include ${CMAKE_CURRENT_LIST_DIR}/boards/m5stick/include ${CMAKE_CURRENT_LIST_DIR}/config)

SET_PROPERTY(SOURCE ${ASSEMBLY_FILES} PROPERTY LANGUAGE C)
SET_SOURCE_FILES_PROPERTIES(${ASSEMBLY_FILES} PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp -D __riscv64")

ADD_LIBRARY(components
        ${LIB_SRC}
        )
SET_TARGET_PROPERTIES(components PROPERTIES LINKER_LANGUAGE C)
