The goal of this simple program is to make sure that your 
environment has all the supported features and libraries
to participate in Optiver's workshop.

Requirements:

* Google Benchmark (https://github.com/google/benchmark)
* C++-14 capable compiler
* CMake 3.1+
* Other tools: perf, valgrind, kcachegrind

On recent Ubuntu, you can install all of the above with:
$ apt install g++ cmake perf-tools-unstable libpapi-dev valgrind kcachegrind

Build instructions:

- create and use out-of-source build directory
$ mkdir ../build

- configure the sources. If Google Benchmark is installed outside of standard location, set BENCHMARK_ROOT variable

$ cd ../build
$ cmake ../source -DCAMKE_BUILD_TYPE=RelWithDebInfo -DBENCHMARK_ROOT=/opt/google/benchmark
$ make