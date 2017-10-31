#include <benchmark/benchmark.h>

#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <random>

#if __has_include(<experimental/string_view>)
	#include <experimental/string_view>
	using std::experimental::string_view;
#else
	#include <string_view>
	using std::string_view;
#endif

static std::random_device rd;
static std::uniform_int_distribution<int> dist(32, 128);

static std::string CreateRandomString()
{

	std::size_t len = dist(rd);
	std::string out;
	out.reserve(len);
	for(std::size_t i = 0; i < len; i++)
		out.push_back(dist(rd));
	
	return out;
}

static std::vector<std::string> CreateVectorOfRandomStrings(int len)
{
	std::vector<std::string> out;
	out.reserve(len);
	for(int i = 0; i < len; i++)
		out.push_back(CreateRandomString());

	return out;
}

template<typename ContainerT>
static void CopyBenchmark(benchmark::State& state)
{
	auto length = state.range(0);
	state.counters["length"] = length;
	
	auto source = CreateVectorOfRandomStrings(length);
	ContainerT target;

	while(state.KeepRunning())
		benchmark::DoNotOptimize(std::copy(source.begin(), source.end(), std::back_inserter(target)));
}

BENCHMARK_TEMPLATE(CopyBenchmark, std::vector<std::string>)->RangeMultiplier(4)->Range(1<<4, 1<<10);
BENCHMARK_TEMPLATE(CopyBenchmark, std::list<std::string>)->RangeMultiplier(4)->Range(1<<4, 1<<10);

BENCHMARK_TEMPLATE(CopyBenchmark, std::vector<string_view>)->RangeMultiplier(4)->Range(1<<4, 1<<10);
BENCHMARK_TEMPLATE(CopyBenchmark, std::list<string_view>)->RangeMultiplier(4)->Range(1<<4, 1<<10);

BENCHMARK_MAIN();