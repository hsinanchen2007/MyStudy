### 解题思路
因为同一组答案不能有重复数字，所以我们人为地控制每组答案是一个递增数组，同时这也避免了出现多组相同的组合。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int tmpStore[10];           /* 每一条路上的数字都由它存储，到达终点且符合条件整体赋值给res */
int target;

void traceBack(int** res, int* returnSize, int level, int k, int cur, int start) {
    if (k == level) {
        if (cur == target) {        /* 已经枚举了k个数字，若符合，则输出答案 */
            res[*returnSize] = malloc(sizeof(int) * k);
            memcpy(res[*returnSize], tmpStore, k * sizeof(int));
            (*returnSize)++;
        }

        return;
    }
    
    if (cur >= target)              /* 剪枝，当数组中少于k个数字就已经超过或等于目标值就退出 */
        return;
    
    for (int i = start; i <= 9; i++) {
        tmpStore[level] = i;
        traceBack(res, returnSize, level + 1, k, cur + i, i + 1);
        /* 这里的最后一个参数用i+1，实现上述所说的思路，避免重复 */
    }

    return;
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * 1000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    target = n;
    
    
    traceBack(res, returnSize, 0, k, 0, 1);
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = k;
    return res;
}
```