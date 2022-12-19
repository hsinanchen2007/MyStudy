### 解题思路
两数组合并，然后排序，直接找中位数

### 代码

```c
int CMP(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    
    int i;
    int count = nums1Size + nums2Size;
    double mid;
    int array[count];

    for (i = 0; i < nums1Size; i++) {
        array[i] = nums1[i];
    }
    for (i = 0; i < nums2Size; i++) {
        array[nums1Size + i] = nums2[i];
    }

    qsort(array, count, sizeof(int), CMP);
    
    if (count%2 == 0) {
        mid = (double)(array[count/2 - 1] + array[count/2]) /2; 
    } else {
        mid = (double)array[count/2];
    }

    return mid;
}
```