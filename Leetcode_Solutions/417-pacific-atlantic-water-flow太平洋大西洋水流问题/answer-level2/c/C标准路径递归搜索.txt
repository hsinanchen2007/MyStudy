### 解题思路
![image.png](https://pic.leetcode-cn.com/24a2f3942a79f837e0a9bde14434a79ec7e72febf57a24741078f63f8cf30a39-image.png)

遍历每1个点，查找是否可以同时到达两大洋

### 代码

```c
void CheckLand(int **matrix, int i, int j, int line, int col, bool *canTai, bool *canDa, int **vis)
{
    if (i < 0 || i >= line || j < 0 || j >= col || vis[i][j] == 1) {
        return;
    }

    if (i == 0 || j == 0) {
        *canTai = true;
    }
    if (i == line - 1 || j == col - 1) {
        *canDa = true;
    }

    //都可以到达
    if (*canTai && *canDa) {
        return;
    }

    vis[i][j] = 1;
    //检查4个方向是否可以流动
    int pos[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int x, y;
    for (int k = 0; k < 4; k++) {
        x = i + pos[k][0];
        y = j + pos[k][1];
        if (x < 0 || x >= line || y < 0 || y >= col) {
            continue;
        }
        if (matrix[i][j] >= matrix[x][y]) {
            CheckLand(matrix, x, y, line, col, canTai, canDa, vis);
            if (*canTai && *canDa) {
                vis[i][j] = 0;
                return;
            }
        }
    }
    vis[i][j] = 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pacificAtlantic(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int line = matrixSize;
    int col = 0;
    if (line > 0) {
        col = matrixColSize[0];
    }
    int **retPos = malloc(sizeof(int *) * line * col + sizeof(int *));
    *returnColumnSizes = malloc(sizeof(int) * line * col + sizeof(int));
    *returnSize = 0;

    printf("line:%d col:%d\n", line, col);

    if (matrixSize == 0) {
        return retPos;
    }

    int **vis = malloc(sizeof(int *) * line);
    for (int i = 0; i < line; i++) {
        vis[i] = malloc(sizeof(int) * col);
    }

    bool canTai, canDa;
    for (int i = 0; i < line; i++)
        for (int j = 0; j < col; j++) {
            canTai = false;
            canDa = false;
            CheckLand(matrix, i, j, line, col, &canTai, &canDa, vis);
            if (canTai && canDa) {
                retPos[*returnSize] = malloc(sizeof(int) * 2);
                (*returnColumnSizes)[*returnSize] = 2;
                retPos[*returnSize][0] = i;
                retPos[*returnSize][1] = j;
                *returnSize += 1;
            }
    }

    for (int i = 0; i < line; i++) {
        free(vis[i]);
    }
    free(vis);

    return retPos;
}
```