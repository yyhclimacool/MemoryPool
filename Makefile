all: mem

mem: main.cpp StackAlloc.hpp MemoryPool.hpp
	g++ -g -o mem -std=c++11 main.cpp

clean:
	rm -rf mem
