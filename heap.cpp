// heap.cpp
// Diba Mirza
#include "heap.h"
#include <iostream>
using std::cout;

void Heap::bubbleDown(int i) {
    int n = vdata.size();
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < n && vdata[left] < vdata[smallest]) smallest = left;
        if (right < n && vdata[right] < vdata[smallest]) smallest = right;
        if (smallest == i) break;
        std::swap(vdata[i], vdata[smallest]);
        i = smallest;
    }
}

void Heap::bubbleUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (vdata[i] < vdata[parent]) {
            std::swap(vdata[i], vdata[parent]);
            i = parent;
        } else break;
    }
}

Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    vdata.assign(start, end);
    for (int i = (int)vdata.size() / 2 - 1; i >= 0; i--) {
        bubbleDown(i);
    }
}

void Heap::push(int value) {
    vdata.push_back(value);
    bubbleUp((int)vdata.size() - 1);
}

void Heap::pop() {
    if (vdata.empty()) return;
    vdata[0] = vdata.back();
    vdata.pop_back();
    if (!vdata.empty()) bubbleDown(0);
}

int Heap::top() {
    return vdata[0];
}

bool Heap::empty() {
    return vdata.empty();
}
