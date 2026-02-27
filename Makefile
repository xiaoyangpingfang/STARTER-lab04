all: examheap

examheap: examheap.cpp heap.cpp heap.h
	g++ -std=c++11 -o examheap examheap.cpp heap.cpp
