#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BublleSort.h"


int main() {
    int n = 20000;

    std::cout << "Normal array test:" << std::endl;
    //测试普通分布的无序数组
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("SelectionSort", selectionSort, arr1, n);
    SortTestHelper::testSort("InsertionSort", insertionSort, arr2, n);
    SortTestHelper::testSort("BubbleSort", bubbleSort, arr3, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;


    std::cout << "Nearly sorted array test:" << std::endl;
    //测试几乎有序的无序数组：插入排序对于几乎有序的无序列队排序表现优异
    int *arr4 = SortTestHelper::generateNearlyOrderedArray(n, 200);
    int *arr5 = SortTestHelper::copyIntArray(arr3, n);
    int *arr6 = SortTestHelper::copyIntArray(arr3, n);
    SortTestHelper::testSort("Selecttion", selectionSort, arr4, n);
    SortTestHelper::testSort("Insertion", insertionSort, arr5, n);
    SortTestHelper::testSort("BubbleSort", bubbleSort, arr6, n);
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    return 0;
}