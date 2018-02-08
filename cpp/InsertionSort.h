//
// Created by andy on 18-2-7.
//

#ifndef SELECTIONSORT_INSERTIONSORT_H
#define SELECTIONSORT_INSERTIONSORT_H

#include <iostream>

template <typename T>
void insertionSort(T *arr, int n)
{
    /*
    //开销较大的普通方法，进行了太多次的交换
    //总结起来就是，从i开始比，和上邻居比，比上邻居小，交换，继续，比上邻居大跳出
    for(int i = 1; i < n; i++)
    {
        //寻找arr[i]合适的插入位置
        for(int j = i; j > 0 && arr[j] < arr[j-1]; j--)
            std::swap(arr[j], arr[j-1]);
    }
     */

    //优化厚的方法，避免了多次交换
    //总结起来就是，从i开始比，和上邻居比，比上邻居小，上邻居右移一位，继续，比邻上邻居大或到左边尽头，跳出，当前位置插入这个元素
    for(int i = 1; i < n; i++)
    {
        T e = arr[i];
        int j;
        for(j = i; j > 0 && e < arr[j-1]; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

}

#endif //SELECTIONSORT_INSERTIONSORT_H
