#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "sorteermethode.h"

template <class T>
class SelectionSort : public Sorteermethode<T> {
  public:
    void operator()(vector<T> &v) const override {
        for (int i = v.size() - 1; i > 0; i--) {
            int imax = i;
            for (int j = 0; j < i; j++) {
                if (v[j] > v[imax]) {
                    imax = j;
                }
            }
            if(imax != i){
                std::swap(v[i], v[imax]);
            }
        }
    }

    virtual ~SelectionSort() {} // todo
};

#endif
