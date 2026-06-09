```c

#define SIZE 155
#define DIR_ROW 4
#define DIR_COL 2

bool g_vis[2][SIZE][SIZE];
const int DIR[DIR_ROW][DIR_COL] = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0}
};

void Dfs(int** matrix, int row, int col, int x, int y, int preHeight, int choose)
{
    if (x < 0 || y < 0 || x >= row || y >= col || preHeight > matrix[x][y] || g_vis[choose][x][y]) {
        return ;
    }

    g_vis[choose][x][y] = true;
    int i;
    for (i = 0; i < DIR_ROW; ++i) {
        Dfs(matrix, row, col, x + DIR[i][0], y + DIR[i][1], matrix[x][y], choose);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pacificAtlantic(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    memset(g_vis, 0, sizeof(g_vis));
    int i, j;
    int row = matrixSize;
    int col = matrixColSize[0];

    for (i = 0; i < row; ++i) {
        Dfs(matrix, row, col, i, 0, 0, 0);
        Dfs(matrix, row, col, i, col - 1, 0, 1);
    }

    for (i = 0; i < col; ++i) {
        Dfs(matrix, row, col, 0, i, 0, 0);
        Dfs(matrix, row, col, row - 1, i, 0, 1);
    }

    *returnSize = 0;
    int** ret = (int**)malloc(sizeof(int*) * row * col);
    *returnColumnSizes = (int*)malloc(sizeof(int) * row * col);

    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            if (g_vis[0][i][j] && g_vis[1][i][j]) {
                ret[*returnSize] = (int*)malloc(sizeof(int) * 2);
                (*returnColumnSizes)[*returnSize] = 2;
                ret[*returnSize][0] = i;
                ret[*returnSize][1] = j;
                ++(*returnSize);
            }
        }
    }
    return ret;
}

```