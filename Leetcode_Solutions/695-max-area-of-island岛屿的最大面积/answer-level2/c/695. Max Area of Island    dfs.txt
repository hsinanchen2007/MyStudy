### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))

int dfs(int **grid, int gridSize, int gridColSize, int row, int col){
    if(row < 0 || row >= gridSize || col < 0 || col >= gridColSize)
        return 0;
    int count = 0;
    if(grid[row][col] == 1){
        count++;
        grid[row][col] = 0;
        count += dfs(grid, gridSize, gridColSize, row - 1, col);
        count += dfs(grid, gridSize, gridColSize, row + 1, col);
        count += dfs(grid, gridSize, gridColSize, row, col - 1);
        count += dfs(grid, gridSize, gridColSize, row, col + 1);
        //printf("row=%d col=%d,count=%d\n",row, col, count);
        return count;
    }else
        return 0;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int i = 0, max = 0, j = 0, temp;

    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < gridColSize[0];j++){
            temp = dfs(grid, gridSize, gridColSize[0], i, j);
            max = MAX(temp, max);
        }
    }

    return max;
}
```