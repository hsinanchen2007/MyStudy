### 解题思路
1. 递归连通岛屿
2. 不与边界连通的岛屿算作被包围的

### 代码

```c
int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, -1, 0, 1};
bool dfs(int **grid, int n, int m, int x, int y)
{
    int nx, ny;
    int i;
    bool flag = true;
    grid[x][y] = 1;
    // printf("going: %d %d\n", x, y);
    for (i = 0; i < 4; i++) {
        nx = x + dirx[i];
        ny = y + diry[i];
        // printf("For: %d %d\n", nx, ny);
        if (grid[nx][ny] == 1) {
            continue;
        }
        if (nx <= 0 || ny <= 0 || nx >= n - 1 || ny >= m - 1) {
            flag = false;
            continue;
        }
        if (!dfs(grid, n, m, nx, ny)) {
            flag = false;
        }
    }
    return flag;
}
int closedIsland(int** grid, int gridSize, int* gridColSize){
    int i;
    int j;
    if (gridSize <= 2) {
        return 0;
    }
    int count = 0;
    for (i = 1; i < gridSize - 1; i++) {
        for (j = 1; j < *gridColSize - 1; j++) {
            if (grid[i][j] == 0) {
                if (dfs(grid, gridSize, *gridColSize, i, j)) {
                    // printf("YES: %d %d\n", i, j);
                    count++;
                }
            }
        }
    }
    return count;
}
```