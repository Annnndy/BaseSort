//
// Created by andy on 18-2-8.
//

#ifndef SELECTIONSORT_BUBLLESORT_H
#define SELECTIONSORT_BUBLLESORT_H

#include <iostream>

template <typename T>
void bubbleSort(T *arr, int n)
{
    bool needSort;
    //和相邻的元素比较，不断交换位置，直到尽头
    for(int i = n-1; i > 0; i--)
    {
        needSort = false;
        for(int j = 0; j < i; j++)
        {
            if( arr[j] > arr[j+1])
            {
                std::swap(arr[j],arr[j+1]);
                needSort = true;
            }
        }
        if(!needSort)
            break;
    }
}

#endif //SELECTIONSORT_BUBLLESORT_H
