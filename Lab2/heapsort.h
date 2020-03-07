#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "sorteermethode.h"

template <class T>
void heapify_node(std::vector<T> &v, int parent, int n) {
    int max = parent;
    int l_child = 2 * parent + 1;
    int r_child = 2 * parent + 2;

    if (r_child < n && v[r_child] > v[max]) {
        max = r_child;
    }

    if (l_child < n && v[l_child] > v[max]) {
        max = l_child;
    }

    if (max != parent) {
        std::swap(v[max], v[parent]);
        heapify_node(v, max, n);
    }
}

template <class T>
void build_heap(vector<T> &v) {
    int last_parent = (v.size() - 1 - 1) / 2;
    for (int i = last_parent; i >= 0; i--) {
        heapify_node(v, i, v.size() - 1);
    }
}

template <class T>
class HeapSort : public Sorteermethode<T> {
  public:
    void operator()(vector<T> &v) const override {
        build_heap(v);
        for (int i = v.size() - 1; i >= 0; i--) {
            std::swap(v[i], v[0]);
            heapify_node(v, 0, i);
        }
    }

    virtual ~HeapSort() {} // todo
};

#endif
