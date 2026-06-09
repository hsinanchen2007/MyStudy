### 解题思路
显然，这道题可以直接对数组排序后再返回前k个数，但是最快的排序算法时间复杂度也是$O(n\logn)$，并且全部排序是没有必要的，因为我们只需要返回前k个数，并且不需要顺序。所以考虑快速排序的递归过程，每次递归都将数组分成两部分，所以每次只需要计算出每个部分大小，再对相应的区间进行排序即可，预期的时间复杂度为$O(n)$

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void mysort(int* arr, int k, int left, int right){
    int i = left, j = right, temp = arr[i];
    while(j > i){
        for(;arr[j] >= temp && j > i;j --);
        arr[i] = arr[j];
        for(;arr[i] <= temp && i < j;i ++);
        arr[j] = arr[i];
    }
    arr[i] = temp;
    if(i - left + 1 < k)
        mysort(arr, k - i + left - 1, i + 1, right);
    else if(i - left + 1 > k)
        mysort(arr, k, left, i - 1);
    else
        return;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if(k == 0){
        *returnSize = 0;
        return NULL;
    }
    int i, *result = (int*)calloc(k, sizeof(int));
    *returnSize = k;
    mysort(arr, k, 0, arrSize - 1);
    for(i = 0;i < k;result[i] = arr[i], i ++);
    return result;
}
```