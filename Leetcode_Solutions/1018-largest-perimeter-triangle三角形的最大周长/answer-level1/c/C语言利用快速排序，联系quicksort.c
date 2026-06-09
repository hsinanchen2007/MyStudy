### 解题思路
1 将数组利用快速排序算法进行从大到小排序
2 数组排序完成后，从第三个元素开始一次进行计算
### 代码

```c
int getIndex(int *a, int low, int high)
{
    int tmp = a[low];
    while(low < high)
    {
        while((low < high) && (a[high] <= tmp))
        {
            high--;
        }

        a[low] = a[high];
        while((low < high) && (a[low] >= tmp))
        {
            low++;
        }
        a[high] = a[low];

    }
    a[low] = tmp;
    return low;
}

void quicksort(int *arr, int low, int high)
{
    int index = 0;
    if(low < high)
    {
        index = getIndex(arr, low, high);
        quicksort(arr, low, index-1);
        quicksort(arr, index+1, high);
    }
    return;
}

int largestPerimeter(int* A, int ASize)
{
    if(ASize == 0)
    {
        return 0;
    }

    quicksort(A, 0, ASize -1);

    int rel = 0;
    for(int i = 2; i<ASize;i++)
    {
        if(A[i] + A[i-1] > A[i-2])
        {
            rel = A[i] + A[i-1] + A[i-2];
            break;
        }
    }
    return rel;
}
```