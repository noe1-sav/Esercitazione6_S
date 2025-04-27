#pragma once
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp"


TEST(TestSorting, TestBubbleSort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    SortLibrary::BubbleSort<int>(v);
    std::vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, TestHeapSort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    SortLibrary::HeapSort<int>(v);
    std::vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

