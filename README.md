# About 
The goal of this simple program is to make sure that your 
environment has all the supported features and libraries
to participate in Optiver's workshop.

# Requirements

* Google Benchmark (https://github.com/google/benchmark)
* C++-14 capable compiler (gcc 5+, VisualStudio 2017+)
* CMake 3.1+
* Other tools: perf, valgrind, kcachegrind

On recent Ubuntu/Debian, you can install all of the above with:
```
$ apt install g++ cmake perf-tools-unstable libpapi-dev valgrind kcachegrind
```

# Linux Build
```
$ git clone --recursive git@github.com:maciekgajewski/EnvironmentTest.git
$ cd EnvironmentTest
$ mkdir build
$ cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo .. 
$ make
```

# Windows build instructions
Using VS2017 Native Tools Command Prompt

```
$ git clone --recursive git@github.com:maciekgajewski/EnvironmentTest.git
$ cd EnvironmentTest
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -G "NMake Makefiles" ..
$ nmake
```

