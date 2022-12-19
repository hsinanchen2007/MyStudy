```c
#define DIR_ROW 4
#define DIR_COL 2
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int g_dir[DIR_ROW][DIR_COL] = {
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1}
};

int Dfs(int** grid, int x, int y, int row, int col)
{
    if (grid == NULL) {
        return 0;
    }
    if (x < 0 || y < 0 || x >= row || y >= col || !grid[x][y]) {
        return 0;
    }
    grid[x][y] = 0;
    int ret = 1;
    for (int i = 0; i < DIR_ROW; ++i) {
        ret += Dfs(grid, x + g_dir[i][0], y + g_dir[i][1], row, col);
    }
    return ret;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0) {
        return 0;
    }
    int i, j;
    int ret = 0;
    int tmp = 0;
    for (i = 0; i < gridSize; ++i) {
        for (j = 0; j < gridColSize[i]; ++j) {
            int tmp = Dfs(grid, i, j, gridSize, gridColSize[i]);
            ret = MAX(ret, tmp);
        }
    }
    return ret;
}

```