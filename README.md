# BaseSort
使用C++和Python实现和优化各类基础排序算法

>python folder only a single .py file, but contains different functions.
>the folder cpp contains the cpp files,implement the different sort algorithms in header files.



所有的基础排序都需要进行双重循环，也就是几乎都有$O(n^2)的时间复杂度$。第一层循环的作用是不断的缩小第二层循环的执行范围。第二层循环则体现了具体的排序思想。



## Selection Sort 选择排序


```cpp
template<typename T>
void selectionSort(T *arr, int n)
{
    for(int i = 0; i < n - 1; i++ )
    {
        //寻找[i,n)之间的最小值
        int minIndex = i;
        for(int j = i+1; j < n - 1; j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
```
选择排序的第一层循环从第0个元素开始，然后再[1到n)的范围内去寻找最小的数字。

具体的执行步骤：

1. 选择第0个元素，假设第0个元素是最小的，设为minIndex

    2. 开始从第1个元素遍历，如果第1个元素的值小于假设值（第0个），那么让minIndex改变为第一个元素的下标。

    3. 重复2的步骤，一直遍历到尽头，这个时候最小的元素的下标minIndex就被找出来了。

4. 把找出来的minIndex位置的元素和第0个元素交换，这样第一次循环结束，找到了[0,n)范围内的最小值，并放在arr[0]的位置。

5. 排除已经找的最小值，从第2个元素开始，重复2,3,找到[1,n)之间的最小值，放在arr[1]的位置。

6. 继续缩小范围，寻找最小值，放在前方，直到n-1也被设置位[n-1, n)内的最小值。排序完成。

选择排序，不管数组的排序情况如何，都需要不断的取遍历取值空间中的每一个值。时间复杂度很高。


## Bubble Sort 冒泡排序

```
template <typename T>
void bubbleSort(T *arr, n)
{
    bool needSort = false;
    for( int i = n - 1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                needSort = true;
            }
        }
        if(!needSort)
        {
            break;
        }
    }
}
```

## Insertion Sort 插入排序
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