cmake_minimum_required(VERSION 3.0.2)
project(pycrctest)


add_custom_target(crc
  SOURCES crc.c crc.h
)
add_custom_command(
    OUTPUT crc.c COMMAND python3 ${PROJECT_SOURCE_DIR}/pycrc/pycrc.py  --model crc-32 --algorithm table-driven --generate c -o ${CMAKE_BINARY_DIR}/crc.c
)
add_custom_command(
    OUTPUT crc.h COMMAND python3 ${PROJECT_SOURCE_DIR}/pycrc/pycrc.py  --model crc-32 --algorithm table-driven --generate h -o ${CMAKE_BINARY_DIR}/crc.h
)

add_executable(crctest main.c ${CMAKE_BINARY_DIR}/crc.c)
include_directories(${CMAKE_BINARY_DIR})

add_dependencies(crctest crc)
