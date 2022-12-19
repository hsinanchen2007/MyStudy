### 解题思路
1. 给第一个位置选数字，有0-numsSize中可能
2. 递归选第二个，传一个flag表明哪些nums已被选过
3. 选好了（idx == numsSize-1）之后记录结果

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrace(int **result, int *resultIdx, int *nums, int numsSize, int *ans, int idx, int *flag) {
    if (idx == numsSize-1) {
        int i;
        int *tmp = (int*)malloc(sizeof(int) * numsSize);
        memcpy(tmp, ans, sizeof(int) * numsSize);
        result[*resultIdx] = tmp;
        *resultIdx += 1;
        return;
    }

    int i;
    for (i=0; i<numsSize; i++) {
        if (flag[i]) continue;
        ans[idx+1] = nums[i];
        flag[i] = 1;
        backtrace(result, resultIdx, nums, numsSize, ans, idx+1, flag);
        flag[i] = 0;
    }
    
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int i;
    int size = 1;
    for (i=1; i<=numsSize; i++) size *= i;
    int **result = (int**)malloc(sizeof(int*) * size);
    int *resultCol = (int*)malloc(sizeof(int) * size);
    for (i=0; i<size; i++) resultCol[i] = numsSize;

    int flag[numsSize];
    int ans[numsSize];
    int resultIdx = 0;
    memset(flag, 0, sizeof(int)*numsSize);

    for (i=0; i<numsSize; i++) {
        flag[i] = 1;
        ans[0] = nums[i];
        backtrace(result, &resultIdx, nums, numsSize, ans, 0, flag);
        flag[i] = 0;
    }

    *returnSize = size;
    *returnColumnSizes = resultCol;
    return result;
}
```