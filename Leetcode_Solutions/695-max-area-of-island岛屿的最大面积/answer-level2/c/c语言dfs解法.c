### 解题思路
此处撰写解题思路

### 代码

```c
int dis[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int **grid, int gridSize, int gridColSize, int newstart, int *max, int i, int j, int **visited) {
    for (int k = 0; k < 4; k++) {
        int newi = i + dis[k][0];
        int newj = j + dis[k][1];
        
        if (newi >= 0 && newi < gridSize && newj >= 0 && newj < gridColSize &&
            grid[newi][newj] == 1 && visited[newi][newj] == 0)
            {
                //printf("%d,%d, %d\n", newi, newj, *max);
                visited[newi][newj] = 1;
                (*max)++;
                dfs(grid, gridSize, gridColSize, 0, max, newi, newj, visited);
            }
    }
    return;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int max = 1;
    int res = 0;
    int **visited;
    visited = (int**)malloc(sizeof(int*) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        visited[i] = (int*)malloc(sizeof(int) * (*gridColSize));
    }
    for (int i = 0 ;i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            visited[i][j] = 0;
        }
    }
    for (int i = 0 ;i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1 && visited[i][j] == 0) {
                max = 1;
                visited[i][j] = 1;
                dfs(grid, gridSize, *gridColSize, 0, &max, i, j, visited);
                if (res < max) {
                    res = max ;
                }
            }
                
        }
    }
    return res;
}
```