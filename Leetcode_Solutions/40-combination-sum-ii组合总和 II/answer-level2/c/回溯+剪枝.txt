### 解题思路
去除重复元素最好的方式就是排序，让最后的输出按照递增或递减输出，这样子保证不会重复组合。

### 代码

```c
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int isNeedToSwap(int* candidates, int target, int curVal, int start, int end)
{
    if (start > 0) {
        if (candidates[end] < candidates[start - 1]) {
            return 0;
        }
    }
    for (int i = start; i < end; i++) {
        if (candidates[i] == candidates[end]) {
            /* 之前已出现过，无需交换 */
            return 0;
        }
    }
    if (curVal + candidates[end] > target) {
        return 0;
    } else {
        return 1;
    }
}

void dfs(int* candidates, int candidatesSize, int target, int curVal, int start, int *returnSize, int *returnColumnSizes, int **result)
{
    if (curVal == target) {
        /*
        for (int i = 0; i < start; i++) {
            printf("%d ", candidates[i]);
        }
        printf("\n");
        */
        returnColumnSizes[*returnSize] = start;
        result[*returnSize] = (int *)malloc(start * sizeof(int));
        for (int i = 0; i < start; i++) {
            result[*returnSize][i] = candidates[i];
        }
        *returnSize += 1;        
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (isNeedToSwap(candidates, target, curVal, start, i)) {
            swap(&candidates[start], &candidates[i]);
            curVal += candidates[start];
            dfs(candidates, candidatesSize, target, curVal, start + 1, returnSize, returnColumnSizes, result);
            curVal -= candidates[start];
            swap(&candidates[start], &candidates[i]);
        }
    }
    return;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    if (candidates == NULL || candidates == 0 || returnSize == NULL) {
        return NULL;
    }
    int **result = (int **)malloc(10000 * sizeof(int *));
    memset(result, 0, 10000 * sizeof(int *));
    int *returncolumnSizes = (int *)malloc(10000 * sizeof(int));
    memset(returncolumnSizes, 0, 10000 * sizeof(int));
    *returnSize = 0;
    dfs(candidates, candidatesSize, target, 0, 0, returnSize, returncolumnSizes, result);
    *returnColumnSizes = returncolumnSizes;
    return result;
}
```