cmake_minimum_required(VERSION 3.8)

project(Chapter14-Parallel_Algorithms_Benchmarks)

file(GLOB BM_SRC_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.cpp")

foreach(CPP_FILE ${BM_SRC_FILES})
  string(REPLACE ".cpp" "" EXE_NAME ${CPP_FILE})
  add_executable(${EXE_NAME} ${CPP_FILE})
  target_link_libraries(${EXE_NAME} PRIVATE benchmark::benchmark)
endforeach( CPP_FILE ${BM_SRC_FILES} )

