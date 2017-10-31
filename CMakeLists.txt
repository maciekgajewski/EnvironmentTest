project(WorkshopEnviromentTest)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(google_benchmark benchmark EXCLUDE_FROM_ALL)

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
endif()

if(BENCHMARK_ROOT)
	include_directories(${BENCHMARK_ROOT}/include)
	link_directories(${BENCHMARK_ROOT}/lib)
endif()

if(UNIX)
	set(EXTRA_LIBS pthread)
else()
	set(EXTRA_LIBS shlwapi.lib)
endif()

add_executable(test_benchmark
	test_benchmark.cc
)

target_link_libraries(test_benchmark
	benchmark
	${EXTRA_LIBS}
)
