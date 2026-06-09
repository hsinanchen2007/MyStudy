### 解题思路
反向遍历，往高的地方走。
从太平洋开始DFS遍历，遍历到后标记；
从大西样开始DFS遍历，遍历后标记；
标记重叠的部分就是能到的重合部分。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool visited1[151][151];
bool visited2[151][151];
int m;
int n;
void init() {
    int i = 0;
    int j = 0;
    for (i = 0; i < 151; i++) {
        for (j = 0; j < 151; j++) {
            visited1[i][j] = false;
            visited2[i][j] = false;
        }
    }
}

void dfs1(int **matrix, int i, int j, int pre)
{
    //printf("%d %d \n", i , j);
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1) {
        return;
    }
    /* 走到比自己低的地方不符合要求 */
    if (matrix[i][j] < pre) {
        return;
    }

    if (visited1[i][j] == true) {
        return;
    }

    visited1[i][j] = true;

    dfs1(matrix, i + 1, j , matrix[i][j]);
    dfs1(matrix, i - 1, j , matrix[i][j]);
    dfs1(matrix, i, j + 1 , matrix[i][j]);
    dfs1(matrix, i, j - 1,  matrix[i][j]);
}

void dfs2(int **matrix, int i, int j, int pre)
{
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1) {
        return;
    }
    /* 走到比自己低的地方不符合要求 */
    if (matrix[i][j] < pre) {
        return;
    }

    if (visited2[i][j] == true) {
        return;
    }

    visited2[i][j] = true;

    dfs2(matrix, i + 1, j , matrix[i][j]);
    dfs2(matrix, i - 1, j , matrix[i][j]);
    dfs2(matrix, i, j + 1 , matrix[i][j]);
    dfs2(matrix, i, j - 1,  matrix[i][j]);
}

int** pacificAtlantic(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    if (matrixSize == 0 || *matrixColSize == 0 || matrix == NULL) {
        returnColumnSizes[0] = NULL;
        *returnSize = 0;
        return NULL;
    }
    m = matrixSize;
    n = *matrixColSize;
    int count = 0;
    init();

    for(int i = 0; i < matrixSize; i++) {
        dfs1(matrix, i, 0, 0);
    }

    for(int i = 0; i < n; i++) {
        dfs1(matrix, 0, i, 0);
    }

    for(int i = 0; i < matrixSize; i++) {
        dfs2(matrix, i, n - 1, 0);
    }

    for(int i = 0; i < n; i++) {
        dfs2(matrix, m - 1, i, 0);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //printf("%d ", visited1[i][j]);
            if (visited1[i][j] == true && visited2[i][j] == true) {
                count++;
            }
        }
        //printf("\n");
    }
    printf("%d", count);

    int **ret = (int **)malloc(sizeof(int *) * count);
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        ret[i] = (int *)malloc(sizeof(int) * 2);
        returnColumnSizes[0][i] = 2;
    }
    *returnSize = count;

    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited1[i][j] && visited2[i][j]) {
                ret[index][0] = i;
                ret[index][1] = j;
                index++;
            }
        }
    }
    return ret;
}
```