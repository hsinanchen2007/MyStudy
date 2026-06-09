### 解题思路
C语言的孩纸，面对写递归函数时，头很大，因为稍微不留神，函数入参就10+，
不管从美观还是复杂度角度，都不好。本代码提供提供一种解决思路，即增加
全局变量，来间接传递参数。觉得不错的，记得点赞哦！！！

### 代码

```c
int g_row = 0;
int g_col[2000];
int chosen[2000];
int len = 0;

void dfs(int **res, int *candidates, int candidatesSize, int start, int target, int sum)
{
    if (sum == target) {
        res[g_row] = (int *) malloc(sizeof(int) * len);
        for (int i = 0; i < len; i++) {
            res[g_row][i] = chosen[i];
        }
        g_col[g_row] = len;
        g_row++;
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] + sum > target) continue;
        chosen[len++] = candidates[i];
        dfs(res, candidates, candidatesSize, i + 1, target, sum + candidates[i]);
        len--;
    }
}

int cmp(const void *a, const void *b)
{
    return *(int *)a < *(int *)b ? 1 : -1;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int ** res = (int **) malloc(sizeof(int *) * 2000);
    *returnColumnSizes = (int *) malloc(sizeof(int) * 2000);
    g_row = len = 0;
    dfs(res, candidates, candidatesSize, 0, target, 0);
    *returnSize = g_row;
    for (int i = 0; i < g_row; i++) {
        (*returnColumnSizes)[i] = g_col[i];
    }
    return res;
}
```