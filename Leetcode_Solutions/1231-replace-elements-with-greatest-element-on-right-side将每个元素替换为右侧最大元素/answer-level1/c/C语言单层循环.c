### 解题思路
设置函数计算当前右侧最大值，当某处值与之相等时（右侧最大值有有可能变动时）重新计算右侧最大值。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int findMax(int start, int *arr, int arrSize){
    int max = arr[start];
    for(int i = start+1;i<arrSize;i++)
        if(arr[i]>max)
            max = arr[i];
    return max;
}

int* replaceElements(int* arr, int arrSize, int* returnSize){
    int big = findMax(0,arr,arrSize);
    for(int i = 0;i<arrSize-1;i++){
        if(arr[i] == big)
            big = findMax(i+1,arr,arrSize);
        arr[i] = big;
    }
    arr[arrSize-1] = -1;
    *returnSize = arrSize;
    return arr;
}
```