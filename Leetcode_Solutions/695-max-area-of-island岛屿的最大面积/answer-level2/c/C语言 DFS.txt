### 解题思路
C语言 DFS

### 代码

```c
#define MAX_TWO(a, b)    (((a) > (b)) ? (a) : (b))

void DFS(int** grid, int row, int col, int u, int v , int* area) {
    if (grid == NULL || row == 0 || col == 0 || u < 0 || u >= row || v < 0 || v >= col || grid[u][v] != 1) {
        return;
    }

    *area = *area + 1;
    grid[u][v] = 0;

    DFS(grid, row, col, u, v + 1, area);
    DFS(grid, row, col, u + 1, v, area);
    DFS(grid, row, col, u, v - 1, area);
    DFS(grid, row, col, u - 1, v, area);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int con = 0;
    int maxArea = 0;
    
    if (grid == NULL || gridSize == 0 || *gridColSize == 0 || gridColSize == NULL) {
        return 0;
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                con = 0;
                DFS(grid, gridSize, *gridColSize, i, j, &con);
                maxArea = MAX_TWO(con, maxArea);
            }
            
        }
    }

    return maxArea;
}
```