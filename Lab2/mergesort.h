#ifndef MERGESORT_H
#define MERGESORT_H

#include "sorteermethode.h"

template <class T>
void merge(std::vector<T> &v, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = 0;

    if (v[m] <= v[j]) {
        return;
    }

    std::vector<T> hulp(r - l + 1);
    while (i <= m && j <= r) {
        if (v[i] < v[j]) {
            hulp[k] = std::move(v[i]);
            i++;
        }
        else {
            hulp[k] = std::move(v[j]);
            j++;
        }
        k++;
    }

    // rechterdeel hoeft niet gekopieerd worden want is al gesorteerd
    while (i <= m) {
        hulp[k] = std::move(v[i]);
        k++;
        i++;
    }

    // testen of rechterdeel volledig doorlopen is
    int hulp_end;
    if (j > r) {
        hulp_end = hulp.size();
    }
    else {
        hulp_end = j - l;
    }

    for (int i = 0; i < hulp_end; i++) {
        v[l + i] = std::move(hulp[i]);
    }
}

template <class T>
void merge_sort(std::vector<T> &v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // vermijd overflow
        merge_sort(v, l, m);
        merge_sort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

template <class T>
class MergeSort : public Sorteermethode<T> {
  public:
    void operator()(vector<T> &v) const override { merge_sort(v, 0, v.size() - 1); }

    virtual ~MergeSort() {} // todo
};

#endif
