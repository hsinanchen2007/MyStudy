### 解题思路
DFS搜索，因为有负节点，不能剪枝。

### 代码

```c

#define MAX_PATH_LEN 1000
#define MAX_PATH_CNT 1000

int g_paths[MAX_PATH_CNT][MAX_PATH_LEN];
int g_path[MAX_PATH_LEN];
int g_pathLens[MAX_PATH_CNT];
int g_pathCnt;

void dfsTree(struct TreeNode* node, int sum, int curSum, int pathLen)
{
    if (!node) {
        return ;
    }

    curSum += node->val;
    g_path[pathLen] = node->val;
    if (!node->left && !node->right) {
        if (curSum == sum) {
            g_pathLens[g_pathCnt] = pathLen + 1;
            memcpy(g_paths[g_pathCnt], g_path, sizeof(g_path));
            g_pathCnt++;
        }
        return ;
    }

    dfsTree(node->left, sum, curSum, pathLen + 1);
    dfsTree(node->right, sum, curSum, pathLen + 1);
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes)
{
    int *columnSize;
    int **path;

    g_pathCnt = 0;

    dfsTree(root, sum, 0, 0);

    *returnSize = g_pathCnt;

    if (g_pathCnt == 0) {
        return NULL;
    }
    columnSize = (int*)malloc(g_pathCnt * sizeof(int));
    for (int i = 0; i < g_pathCnt; i++) {
        columnSize[i] = g_pathLens[i];
    }
    *returnColumnSizes = columnSize;
    path = (int**)malloc(g_pathCnt * sizeof(int*));
    for (int i = 0; i < g_pathCnt; i++) {
        path[i] = (int*)malloc(columnSize[i] * sizeof(int));
        for (int j = 0; j < columnSize[i]; j++) {
            path[i][j] = g_paths[i][j];
        }
    }

    return path;
}
```