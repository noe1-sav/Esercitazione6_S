#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {
	
template<typename T>
void BubbleSort(vector<T>& v)
{
	for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v.size() - i - 1; ++j) {
            if (v[j] > v[j + 1])
                std::swap(v[j], v[j + 1]);
        }
    }
	
}

template<typename T>
void HeapSort(vector<T>& v){
	make_heap(v.begin(), v.end());
	sort_heap(v.begin(), v.end());
	}

}

