cmake_minimum_required(VERSION 3.14)
project(PianoKeyDetector)

set(CMAKE_CXX_STANDARD 11)

set(CONAN_SYSTEM_INCLUDES ON)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_CURRENT_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)

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
