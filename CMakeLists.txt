set(CMAKE_CXX_STANDARD 14)

if(BENCHMARK_ROOT)
	include_directories(${BENCHMARK_ROOT}/include)
	link_directories(${BENCHMARK_ROOT}/lib)
endif()

if(LINUX)
	set(EXTRA_LIBS pthread)
endif()

add_executable(test_benchmark

	test_benchmark.cc
)

target_link_libraries(list-test_benchmark-becnhmark

	benchmark
	${EXTRA_LIBS}
)