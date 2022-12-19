### 解题思路
此处撰写解题思路

### 代码

```c

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int comp(const void *a, const void *b)
{
    int *pa = (int *)a;
    int *pb = (int *)b;
    return (*pb) - (*pa);
}
int* minSubsequence(int* nums, int numsSize, int* returnSize){
    qsort((void*)nums, numsSize, sizeof(int), comp);
    int i, left, right;
    int sum = 0;
    
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    
    left = 0;
    right = sum;
    for (i = 0; i < numsSize; i++) {
        if (left > right) {
            break;
        }
        left += nums[i];
        right -= nums[i]; 
    }
    
    *returnSize = i;
    return nums;
}
```