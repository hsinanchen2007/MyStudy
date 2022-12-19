### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    if (!nums || numsSize < 1) {
        *returnSize = 0;
        return NULL;
    }

    int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        int j;
        for (j = i + 1; j < i + numsSize; j++) {
            if (nums[j % numsSize] > nums[i]) {
                break;
            }
        }
        if (j == i + numsSize) {
            res[i] = -1;
        }
        else {
            res[i] = nums[j % numsSize];
        }
    }
    return res;
}
```