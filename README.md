The goal of this simple program is to make sure that your 
environment has all the supported features and libraries
to participate in Optiver's workshop.

Requirements:

* Google Benchmark (https://github.com/google/benchmark)
* C++-14 capable compiler (gcc 5+, VisualStudio 2017+)
* CMake 3.1+
* Other tools: perf, valgrind, kcachegrind

On recent Ubuntu, you can install all of the above with:
$ apt install g++ cmake perf-tools-unstable libpapi-dev valgrind kcachegrind

Build instructions:

- Build Google Benchmark

$ git clone <google benchmark url>
$ mkdir benchmark-build
$ cd benchmark-build
$ cmake ../benchmark -DCMAKE_BUILD_TYPE=RelWithDebInfo
$ make
$ sudo make install

- Build this project, create and use out-of-source build directory
$ git clone <this repo>
$ mkdir build

- configure the sources. If Google Benchmark is installed outside of standard location, set BENCHMARK_ROOT variable

$ cd build
$ cmake ../source -DCAMKE_BUILD_TYPE=RelWithDebInfo -DBENCHMARK_ROOT=/opt/google/benchmark
$ make

Windows build instructions, using VS2017 Native Tools Command Prompt

- obtain Google Benchmark

$ git clone <google becnhmark url>
$ mkdir benchmark-build
$ cd benchmark-build
$ cmake ..\benchmark -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=c:/dev/benchmark -G "NMake Makefiles"
$ nmake
$ nmake install

- build this project

$ git clone <this project>
$ mkdir build
$ cd build
$ cmake ..\source -DCMAKE_BUILD_TYPE=RelWithDebInfo -DBENCHMARK_ROOT=c:/dev/benchmark -G "NMake Makefiles"
$ nmake
