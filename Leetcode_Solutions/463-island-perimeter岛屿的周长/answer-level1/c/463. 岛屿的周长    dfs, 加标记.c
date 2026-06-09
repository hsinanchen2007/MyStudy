### 解题思路
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。

网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

 

示例 :

输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

输出: 16


### 代码

```c
//int max;

int dfs(int** grid, int rowSize, int colSize, int row, int col){

    if (row < 0 || row >= rowSize || col < 0 || col >= colSize || grid[row][col] == 0) {
        //max += 1;
        return 1;
    }

    if (grid[row][col] == -1)
        return 0;

    grid[row][col] = -1;
    
    return dfs(grid, rowSize, colSize, row - 1, col) +
            dfs(grid, rowSize, colSize, row + 1, col) +
            dfs(grid, rowSize, colSize, row, col - 1) +
            dfs(grid, rowSize, colSize, row, col + 1);
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int i, j;
    //max = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 1) {
                return dfs(grid, gridSize, gridColSize[0], i, j);
                //return max;
            }
        }
    }
    return 0;
}
```