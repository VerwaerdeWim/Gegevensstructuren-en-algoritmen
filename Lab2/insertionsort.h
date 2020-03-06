#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "sorteermethode.h"

template <class T>
class InsertionSort : public Sorteermethode<T> {
  public:
    void operator()(vector<T> &v) const override {
        int interval = 1;
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

    virtual ~InsertionSort(){} //todo
};

#endif
