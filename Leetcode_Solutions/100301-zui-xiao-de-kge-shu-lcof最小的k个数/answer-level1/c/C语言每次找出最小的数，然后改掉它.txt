### 解题思路
外层循环k次，内层循环遍历每次找出最小的数。然后替换掉它为最大值。
感觉写的不是很好，改掉了原始数据。另执行时间有点长。。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int i, j, min=10000, min_index;
    int* res = (int*)malloc(sizeof(int)*k);
    for(i=0; i<k; i++){
        for(j=0; j<arrSize; j++){
            if(min>arr[j]){
                min = arr[j];
                min_index = j;
            }
        }
        res[i] = min;
        arr[min_index] = 10000;
        min = 10000;
    }
    *returnSize = k;
    return res;
}
```