### 解题思路
dfs访问，设置visited数组。

### 代码

```c
void dfs(char** grid, int gridSize, int gridColSize, int x, int y, int **visted) 
{
    if ((x < 0) || (x >= gridSize)) {
        return;
    }
    if ((y< 0) || (y >= gridColSize)) {
        return;
    }    
    if (visted[x][y] == 1) { // v
        return;
    }
    if (grid[x][y] == '1') {
        visted[x][y] = 1;
        dfs(grid, gridSize, gridColSize, x+1, y, visted);
        dfs(grid, gridSize, gridColSize, x, y+1, visted);
        dfs(grid, gridSize, gridColSize, x-1, y, visted);
        dfs(grid, gridSize, gridColSize, x, y-1, visted);
    }
    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int **visited = (int**)malloc(sizeof(int**) * gridSize);
    if (visited == NULL) {
        return -1;
    }
    for (int i = 0; i < gridSize; i++) {
        visited[i] = (int *)malloc(sizeof(int*) * gridColSize[0]);
        if (visited[i] == NULL) {
            return -1;
        }
        memset(visited[i], 0, sizeof(int)*gridColSize[0]);
    }
    int cnt = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if ((visited[i][j] == 0) && (grid[i][j] == '1')) {
                dfs(grid, gridSize, gridColSize[0], i, j, visited);
                cnt++;
            }
        }
    }
    
    for (int i = 0; i < gridSize; i++) {
        free(visited[i]);
    }
    free(visited);
    return cnt;
}
```