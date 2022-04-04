project(Skeleton)
cmake_minimum_required(VERSION 3.4.3)

# To support both in- and out-of-source builds,
# we check for the presence of the add_llvm_loadable_module command.
# - if this command is not present, we are building out-of-source
set(CMAKE_CXX_STANDARD 14)
if(NOT COMMAND add_llvm_loadable_module)
    if (DEFINED ENV{LLVM_DIR})
        # We need to match the build environment for LLVM:
        # In particular, we need C++11 and the -fno-rtti flag
        if(CMAKE_BUILD_TYPE MATCHES "Debug")
            set(CMAKE_CXX_FLAGS "-std=c++14 -O0 -fno-rtti -fno-pie")
        else()
            set(CMAKE_CXX_FLAGS "-std=c++14 -fPIC -fvisibility-inlines-hidden -Wall -W -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wno-missing-field-initializers -pedantic -Wno-long-long -Wno-maybe-uninitialized -Wdelete-non-virtual-dtor -Wno-comment -Werror=date-time -std=c++11 -g  -fno-exceptions -fno-rtti -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -fno-pie -no-pie")
        endif()
    endif()
endif()

find_package(LLVM REQUIRED CONFIG)

add_definitions(${LLVM_DEFINITIONS})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)


# message(STATUS "LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")

include_directories(${LLVM_INCLUDE_DIRS})

include_directories(
    ${PROJECT_SOURCE_DIR}
)

add_subdirectory(skeleton_lib)
