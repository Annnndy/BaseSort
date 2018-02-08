//
// Created by andy on 18-2-7.
//

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include <iostream>
#include <cassert>

namespace SortTestHelper
{

    //生成有n个元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR)
    {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        std::srand(time(NULL));
        for( int i = 0; i < n; i++)
        {
            arr[i] = std::rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    //生成有n个元素的有序数据，然后随机抽选swapTimes对位置进行交换，最终生成一个近乎有序的无需数组
    int *generateNearlyOrderedArray(int n, int swapTimes)
    {
        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = i;

        std::srand(time(NULL));
        for(int i = 0; i < swapTimes; i++)
        {
            int posx = std::rand()%n;
            int posy = std::rand()%n;
            std::swap(arr[posx], arr[posy]);
        }

        return arr;
    }


    template<typename T>
    void printArray(T *arr, int n)
    {

        for(int i = 0; i < n; i++)
            std::cout<<arr[i]<<" ";
        std::cout<<std::endl;

        return;
    }

    template <typename T>
    bool isSorted(T* arr, int n)
    {
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i+1])
                return false;

        return true;
    }

    template<typename T>
    void testSort(std::string sortName, void(*sort)(T*, int), T* arr, int n)
    {
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));
        std::cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << std::endl;

        return;
    }

    int* copyIntArray(int *arr, int n)
    {
        int *rarr = new int[n];
        std::copy(arr, arr+n, rarr);
        return rarr;
    }

}

#endif //SELECTIONSORT_SORTTESTHELPER_H
