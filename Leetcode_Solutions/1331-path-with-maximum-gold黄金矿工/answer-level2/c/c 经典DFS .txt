错误1，开始的时候没加visited 造成死循环，
错误2 sumValue一开始用指针传进来，一直累加
错误3，col 是列，row 是行，一开始弄反了，而且要把i,j是否有效的判断放在最前面
```
void dfs(int** grid, int i, int j, int gridSize, int gridColSize, int sumValue, int visited[][15],int *max) 
{
    if (i < 0 || j < 0 || i >=gridSize || j >= gridColSize) {
        return;
    }
    if (grid[i][j] == 0 || visited[i][j] == 1) {
        return;
    }
    sumValue = sumValue + grid[i][j];
    if (*max < sumValue) {
        *max = sumValue;
    }
    visited[i][j] = 1;
    dfs(grid, i+1, j, gridSize, gridColSize, sumValue, visited, max);
    dfs(grid, i-1, j, gridSize, gridColSize, sumValue, visited, max);
    dfs(grid, i, j+1, gridSize, gridColSize, sumValue, visited,max);
    dfs(grid, i, j-1, gridSize, gridColSize, sumValue, visited, max);
    visited[i][j] = 0;
}
int getMaximumGold(int **grid, int gridSize, int* gridColSize)
{
    int i;
    int j;
    int sumValue = 0;
    int maxValue = 0;
    int visited[15][15] = {0};
    memset(visited, 0, sizeof(visited));
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] != 0) {
                dfs(grid, i, j, gridSize, *gridColSize, sumValue, visited, &maxValue);
            }
        }
    }
    return maxValue;
}
```
