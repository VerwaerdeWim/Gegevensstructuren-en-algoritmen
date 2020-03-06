#ifndef STLSORT_H
#define STLSORT_H

#include "sorteermethode.h"
#include <algorithm>

template <class T>
class STLSort : public Sorteermethode<T>{
    public:
        void operator()(vector<T> & v) const override {
            sort(v.begin(),v.end());
        }
        virtual ~STLSort(){} //todo
};


#endif

