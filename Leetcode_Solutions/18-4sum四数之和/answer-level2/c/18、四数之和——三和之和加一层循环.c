### 解题思路
1、利用三数之和的解法，內加一层for循环；
2、特殊情况处理（参考了其他的答案）；

### 代码

```c
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int maxRet = numsSize;
    int **ret = (int**)malloc(maxRet * sizeof(int*));
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 3; i++) {
        if (i && nums[i] == nums[i - 1]){
            continue;
        }
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j != i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            int m = j + 1;
            int n = numsSize - 1;
            while (m < n) {
                int tmp = nums[i] + nums[j] + nums[m] + nums[n];
                if (target == tmp) {
                    if (*returnSize == maxRet) {
                        maxRet *= 2;
                        ret = (int**)realloc(ret, maxRet * sizeof(int*));
                    }
                    ret[*returnSize] = (int*)malloc(0x4 * sizeof(int));
                    ret[*returnSize][0] = nums[i];
                    ret[*returnSize][1] = nums[j];
                    ret[*returnSize][2] = nums[m];
                    ret[*returnSize][3] = nums[n];
                    (*returnSize)++;

                    tmp = nums[m];
                    while(m < n && tmp == nums[m]) {
                        m++;
                    }
                    tmp = nums[n];
                    while(m < n && tmp == nums[n]) {
                        n--;
                    }
                } else if (tmp > target) {
                    n--;
                } else {
                    m++;
                }
            }
        }
    }
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++){
        (*returnColumnSizes)[i] = 0x4;
    }
    return ret;
}
```