cmake_minimum_required(VERSION 3.14)
project(PianoKeyDetector)

set(CMAKE_CXX_STANDARD 11)

set(CONAN_SYSTEM_INCLUDES ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(PianoKeyDetector src/main.cpp)
target_include_directories(PianoKeyDetector SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(PianoKeyDetector PUBLIC ${CONAN_LIBS})

if (EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
add_custom_command(
  TARGET PianoKeyDetector
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
  ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
endif()
