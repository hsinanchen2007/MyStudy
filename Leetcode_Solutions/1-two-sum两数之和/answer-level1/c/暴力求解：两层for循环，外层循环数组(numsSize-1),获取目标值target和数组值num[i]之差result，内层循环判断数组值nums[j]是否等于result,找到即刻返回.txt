### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *resultPtr = NULL;
    *returnSize = 0;
    for(int i=0;i<numsSize-1;i++) {
        int result = target-nums[i];
        for(int j=i+1;j<numsSize;j++) {
            if(nums[j] == result) {
                resultPtr = (int *)calloc(2, sizeof(int));;
                *returnSize = 2;
                resultPtr[0] = i;
                resultPtr[1] = j;
                return resultPtr;
            }
        }
    }
    return resultPtr;
}
```