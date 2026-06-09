### 解题思路
采用DFS，在搜索遍历的过程中根据模块数据返回有效周长，同时题目表明只有一个岛屿，所以只需找到一个陆地展开一次DFS即可得到整个岛屿周长。

### 代码

```c
int DFS(int** grid, int row, int col, int u, int v) {
    int line = 0;

    if (grid == NULL) {
        return 0;
    }

    if (u < 0 || u >= row || v < 0 || v >= col || grid[u][v] == 0) {  // 已到达边界或水域则返回1，代表这是一条有效的周长边
        return 1;
    }

    if (grid[u][v] == 2) {  // 如果是2证明已访问过，不构成有效周长
        return 0;
    }

    grid[u][v] = 2;
    // 搜寻遍历四个方向
    line = line + DFS(grid, row, col, u, v + 1);
    line = line + DFS(grid, row, col, u + 1, v);
    line = line + DFS(grid, row, col, u, v - 1);
    line = line + DFS(grid, row, col, u - 1, v);

    return line;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int temp = 0;

    if (grid == NULL || gridSize == 0 || *gridColSize == 0 || gridColSize == NULL) {
        return 0;
    }
    
    // 只有一个岛屿，所以只需找到一个陆地并展开DFS即可获得整个岛屿的周长
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                temp = DFS(grid, gridSize, *gridColSize, i, j);
                return temp;
            }
        }
    }
    
    return 0;
}
```