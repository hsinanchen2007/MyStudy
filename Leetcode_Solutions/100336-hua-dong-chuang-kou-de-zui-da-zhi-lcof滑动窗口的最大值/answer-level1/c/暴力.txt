### 解题思路
暴力：每一移动一格，取最大值，返回

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getMaxNum(int *arr, int numSize)
{
    int maxNum = INT_MIN;
    for (int i = 0; i < numSize; i++) {
        maxNum = (maxNum > arr[i]) ? maxNum : arr[i];
    }

    return maxNum;
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int *returnValue = NULL;
    if((nums == NULL) || (numsSize == 0) || (k == 0)) {
        *returnSize = 0;
        return NULL;
    } 
    if (numsSize <= k) {
        returnValue = (int *)malloc(sizeof(int));
        *returnValue = getMaxNum(nums, numsSize);
        *returnSize = 1;
        return returnValue;
    }

    *returnSize = numsSize - k + 1;
    returnValue = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++)  {
        returnValue[i] = getMaxNum(nums+i, k);
    }

    return returnValue;

}
```