### 解题思路
算法：外层循环（递归（内层循环））
1、外层循环控制元素个数，递减；
2、递归+内层循环，遍历所有组合。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define BUF_SIZE 1000

int g_stack[BUF_SIZE] = {0};
int **g_result = NULL;
int *g_resultColumnSize = NULL;
int g_resultSize = 0;

void doLoop(int* candidates, int candidatesSize, int target, int sum, int condidateId, int stackId){
    int i;

    sum += candidates[condidateId];
    if (sum > target) {
        return;
    }

    g_stack[stackId++] = candidates[condidateId];

    if (sum != target) {
        for (; condidateId < candidatesSize; condidateId++) {
            doLoop(candidates, candidatesSize, target, sum, condidateId, stackId);
        }
    }
    else {
        g_result[g_resultSize] = malloc(stackId << 2);
        memcpy(g_result[g_resultSize], g_stack, stackId << 2);
        g_resultColumnSize[g_resultSize] = stackId;
        g_resultSize++;
    }
    
    return;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int i;

    g_result = malloc(BUF_SIZE);
    memset(g_result, 0, BUF_SIZE);

    g_resultColumnSize = malloc(BUF_SIZE);
    memset(g_resultColumnSize, 0, BUF_SIZE);

    g_resultSize = 0;

    for (i = 0; i < candidatesSize; i++) {
        doLoop(candidates, candidatesSize, target, 0, i, 0);
    }

    *returnSize = g_resultSize;
    *returnColumnSizes = g_resultColumnSize;

    return g_result;
}
```