### 解题思路
话不多说看代码吧

### 代码

```c
int dfs(int *grid[], int i, int j, int *visited[], int row, int col){
    visited[i][j] = 1;
    int count = 1;

    if(i - 1 >= 0 && grid[i - 1][j] && !visited[i - 1][j])
        count += dfs(grid, i - 1, j, visited, row, col);
    if(j - 1 >= 0 && grid[i][j - 1] && !visited[i][j - 1])
        count += dfs(grid, i, j - 1, visited, row, col);
    if(i + 1 < row && grid[i + 1][j] && !visited[i + 1][j])
        count += dfs(grid, i + 1, j, visited, row, col);
    if(j + 1 < col && grid[i][j + 1] && !visited[i][j + 1])
        count += dfs(grid, i, j + 1, visited, row, col);

    return count;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if(gridSize == 0)   return 0;

    int row = gridSize, col = gridColSize[0];
    int max = 0, count = 0;
    int visited[row][col];
    int *p_grid[row], *p_visited[row];

    for(int i = 0; i < row; ++i){
        memset(visited[i], 0, sizeof(int) * col);
        p_grid[i] = grid[i];
        p_visited[i] = visited[i];
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(grid[i][j] == 1 && visited[i][j] == 0){
                count = dfs(p_grid, i, j, p_visited, row, col);
                if(count > max)
                    max = count;
            }
        }
    }

    return max;
}
```