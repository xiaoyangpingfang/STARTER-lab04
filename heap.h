// heap.h
// Binary heap tree header file for CS 24 lab
// Diba Mirza
#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <vector>
class Heap{
 public:
    Heap() {}  // default constructor
    Heap(std::vector<int>::iterator start, std::vector<int>::iterator end);
    void push(int value);
    void pop();
    int top();
    bool empty();
 private:
    std::vector<int> vdata;
    void bubbleDown(int i);
    void bubbleUp(int i);
};
#endif
