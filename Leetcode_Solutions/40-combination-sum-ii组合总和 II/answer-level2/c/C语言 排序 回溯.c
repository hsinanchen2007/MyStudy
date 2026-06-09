### 解题思路
C语言 回溯

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MALLOC_LEN 1024
int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
/* 
    begin：当前从第几层开始
    *tmp：用于保存当次的递归路径
    tmp_len：当前递归路径的长度
*/
void dfs(int * candidates, int candidatesSize, int target, int begin, int **ans,
         int * returnColumnSizes, int *len, int *tmp, int tmp_len)
{
    if (target == 0) {
        /* 回溯算法的输出内存空间申请需要在dfs里面做，防止初始化申请空间爆炸 */
        ans[*len] = (int*)malloc(sizeof(int) * tmp_len);
        for (int i = 0; i < tmp_len; i++) {
            ans[*len][i] = tmp[i];
        }
        returnColumnSizes[*len] = tmp_len;
        (*len)++;
        return;
    }
    for (int i = begin; i < candidatesSize; i++) {
        if (target < 0) {
            return;
        }
        /* 剪枝，去重 */
        if (i > begin && candidates[i] == candidates[i - 1]) {
            continue;
        }
        tmp[tmp_len] = candidates[i];
        /* 元素不能重复使用，DFS的索引需要移位 */
        dfs(candidates, candidatesSize, target - candidates[i], i + 1, ans,
            returnColumnSizes, len, tmp, tmp_len + 1);
    }
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize,
                     int** returnColumnSizes)
{
    int i;
    int len = 0;
    int tmp[MALLOC_LEN] = {0};
    int **ans = (int**)malloc(sizeof(int*) * MALLOC_LEN);
    /* 常规内存申请在此处做，回溯深度优先时在子函数中申请 */
    *returnColumnSizes = (int*)malloc(sizeof(int) * MALLOC_LEN);

    /* 保证递归树的顺序 */
    qsort(candidates, candidatesSize, sizeof(int), cmp);

    dfs(candidates, candidatesSize, target, 0, ans, *returnColumnSizes, &len, tmp, 0);
    *returnSize = len;

    return ans;
}
```