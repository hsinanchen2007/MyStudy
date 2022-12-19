### 解题思路
此处撰写解题思路

### 代码

```c
#define MAXNUM 15

int g_visit[MAXNUM][MAXNUM] = {0};

int Max(int a, int b, int c, int d)
{
    int e = (a > b) ? a : b;
    int f = (c > d) ? c : d;

    return (e > f) ? e : f;
}

int Dfs(int i, int j, int** grid, int m, int n)
{
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1) {
        return 0;
    }

    if (grid[i][j] == 0 || g_visit[i][j] == -1) {
        return 0;
    }
    
    g_visit[i][j] = -1;

    int a = Dfs(i + 1, j, grid, m, n) + grid[i][j];
    int b = Dfs(i, j + 1, grid, m, n) + grid[i][j];
    int c = Dfs(i - 1, j, grid, m, n) + grid[i][j];
    int d = Dfs(i, j - 1, grid, m, n) + grid[i][j];   

    g_visit[i][j] = 0;      

    return Max(a, b, c, d); 
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize)
{
    int rel = 0;
    int temp = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] != 0) {
                memset(g_visit, 0, sizeof(g_visit));
                temp = Dfs(i, j, grid, gridSize, gridColSize[0]);
                //printf("i=%d, j=%d, temp=%d\n", i, j, temp);
                if (rel < temp) {
                    rel = temp;
                }               
            }
        }    
    }

    return rel;
}
```