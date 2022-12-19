### 解题思路
此处撰写解题思路

### 代码

```c

int search(int** grid, int gridSize, int colSize, int row, int col){
    if(row < 0 || row == gridSize || col < 0 || col == colSize || grid[row][col] == 0)
        return 0;
    grid[row][col] = 0;
    return 1 + search(grid, gridSize, colSize, row - 1, col)
             + search(grid, gridSize, colSize, row + 1, col)
             + search(grid, gridSize, colSize, row, col - 1)
             + search(grid, gridSize, colSize, row, col + 1);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if(grid == NULL || gridColSize == NULL)
        return 0;
    int result = 0, ans;
    for(int i = 0; i < gridSize; ++i){
        for(int j = 0; j < *gridColSize; ++j){
            ans = search(grid, gridSize, *gridColSize, i, j);
            result = result > ans ? result : ans;
        }
    }
    return result;
}


```