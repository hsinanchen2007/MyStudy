### 解题思路

用C处理写暴力法，就是二层循环。

唯一要特别注意的是， 如果数组大小或者滑动窗口为0，那么要特别的设置下returnSize的值，否则会报错。

哎，C语言处理这种返回数组的题目就是要特别考虑数组为空的情况。

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){

    if ( numsSize * k == 0 ) {
        *returnSize = 0;
        return NULL;
        
    }
    *returnSize = numsSize - k + 1;
    int *ret = (int *)malloc(sizeof(int) * *returnSize);

    for (int i = 0; i < *returnSize; i++){
        int max = nums[i];
        for ( int j = i; j < i+k; j++){
            max = max < nums[j] ? nums[j] : max;
        }
        ret[i] = max;
    }
    return ret;

}


```