#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "sorteermethode.h"
#include <iostream>

template <class T>
void insertion_sort(vector<T> &v, int interval) {
    for (int i = interval; i < v.size(); i++) {
        T storage = std::move(v[i]);

        int j = i - interval;
        while (j >= 0 && storage < v[j]) {
            v[j + interval] = std::move(v[j]);
            j -= interval;
        }
        v[j + interval] = std::move(storage);
    }
}

template <class T>
class ShellSort : public Sorteermethode<T> {
  public:
    void operator()(vector<T> &v) const override {
        for (int i = v.size() / 2; i > 0; i /= 2) {
            insertion_sort(v, i);
        }
    }

    virtual ~ShellSort(){} //todo
};

#endif
