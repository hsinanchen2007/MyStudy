### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    /*
         最大的数为100;
         计数排序,前缀和
    */
    int  pool[105] = {0};
    int  sum[105] = {0};
    int  value;

    int *res = (int *) malloc(numsSize*sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        value = nums[i];
        pool[value]++; /* 记录每个数的个数 */
    }
    /* 前缀和*/
    for( int i = 1; i < 105;  i++) {
        sum[i] = sum[i-1] + pool[i-1];
    }

    for (int i = 0; i < numsSize; i++) {
        value = nums[i];
        res[i] = sum[value];
    }
    *returnSize = numsSize;
    return res;

}
```