### 解题思路
此处撰写解题思路
1、一遍DFS，刷新grid矩阵，并给刷新后的矩阵元素编号归属；
2、逐个填海，O（1）复杂度求最大值。
### 代码

```c
#define MAX 50
int g_row;
int g_col;
int g_seaPos[MAX * MAX][2];
int g_landPos[MAX * MAX][2];
bool g_valid[MAX][MAX];
int g_num[MAX][MAX];
int DFS_Getarea(int **grid, int x, int y)
{
    if (x < 0 || x >= g_row || y < 0 || y >= g_col) {
        return 0;
    }
    if (g_valid[x][y] == 1) {
        return 0;
    }
    if (grid[x][y] == 0) {
        return 0;
    }
    g_valid[x][y] = 1;
    int sum = 1;
    sum += DFS_Getarea(grid, x - 1, y);
    sum += DFS_Getarea(grid, x + 1, y);
    sum += DFS_Getarea(grid, x, y - 1);
    sum += DFS_Getarea(grid, x, y + 1);
    return sum;
}
void UpdataGrid(int **grid)
{
    int landcnt = 0;
    for (int i = 0; i < g_row; i++) {
        for (int j = 0; j < g_col; j++) {
            if (grid[i][j] == 0) {
                continue;
            }
            g_landPos[landcnt][0] = i;
            g_landPos[landcnt][1] = j;
            landcnt++;
        }
    }
    memset(g_num, 0, sizeof(g_num));
    memset(g_valid, 0, sizeof(g_valid));
    int sum = 0;
    int num = 10000;
    for (int i = 0; i < landcnt; i++) {
        int x = g_landPos[i][0];
        int y = g_landPos[i][1];
        if (g_valid[x][y] == 1) {
            continue;
        }
        sum = DFS_Getarea(grid, x, y);
        grid[x][y] = sum;
        g_num[x][y] = num;
        for (int i = 0; i < landcnt; i++) {
            int x = g_landPos[i][0];
            int y = g_landPos[i][1];
            if (g_valid[x][y] == 1 && g_num[x][y] == 0) {
                grid[x][y] = sum;
                g_num[x][y] = num;
            }
        }
        num++;
    }
}
int GetMaxLand(int **grid, int x, int y) 
{
    int tmp[4] = {0};
    int num[4] = {0};
    if (x > 0) {
        tmp[0] = grid[x - 1][y];
        num[0] = g_num[x - 1][y];
    }
    if (y > 0) {
        tmp[1] = grid[x][y - 1];
        num[1] = g_num[x][y - 1];
    }
    if (x < g_row - 1) {
        tmp[2] = grid[x + 1][y];
        num[2] = g_num[x + 1][y];
    }
    if (y < g_row - 1) {
        tmp[3] = grid[x][y + 1];
        num[3] = g_num[x][y + 1];
    }
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (num[i] == num[j]) {
                tmp[i] = 0;
            }
        }
    }
    ret = tmp[0] + tmp[1] + tmp[2] + tmp[3] + ret;
    return ret;
}
int largestIsland(int** grid, int gridSize, int* gridColSize)
{
    g_row = gridSize;
    g_col = gridColSize[0];
    int seacnt = 0;
    for (int i = 0; i < g_row; i++) {
        for (int j = 0; j < g_col; j++) {
            if (grid[i][j] == 1) {
                continue;
            }
            g_seaPos[seacnt][0] = i;
            g_seaPos[seacnt][1] = j;
            seacnt++;
        }
    }
    if (seacnt == 0) {
        return g_row * g_col;
    }
    if (seacnt == g_row * g_col) {
        return 1;
    } 
    int ret = 0;
    UpdataGrid(grid);
    for (int i = 0; i < seacnt; i++) {
        int x = g_seaPos[i][0];
        int y = g_seaPos[i][1];
        int tmp = GetMaxLand(grid, x, y);
        ret = fmax(ret, tmp);
    }
    return ret;
}
```