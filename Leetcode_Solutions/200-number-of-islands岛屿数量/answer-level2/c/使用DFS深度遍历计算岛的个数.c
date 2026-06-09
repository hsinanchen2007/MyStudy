### 解题思路
1、计算岛的个数，思路是采用涂色机制，将1修改为其他值-1
2、每次都向下、向上、向左、向右遍历，如果是1则修改为涂色值
3、然后只需要统计1的个数即可

### 代码

```c
#define RED_NUM -1
void dfs(char **grid, int gridSize, int *gridColSize, int row, int col)
{
    if (row >= gridSize) {
        return;
    }

    if (col >= gridColSize[row]) {
        return;
    }

    grid[row][col] = RED_NUM;
    if ((row + 1 < gridSize) && (grid[row + 1][col] == '1')) {
        dfs(grid, gridSize, gridColSize, row + 1, col);
    }

    if ((col + 1 < gridColSize[row]) && (grid[row][col + 1] == '1')) {
        dfs(grid, gridSize, gridColSize, row, col + 1);
    }

    if ((row - 1 >= 0) && (grid[row - 1][col] == '1')) {
        dfs(grid, gridSize, gridColSize, row - 1, col);
    }

    if ((col - 1 >=0) && (grid[row][col - 1] == '1')) {
        dfs(grid, gridSize, gridColSize, row, col - 1);
    }
    return;
}

int numIslands(char **grid, int gridSize, int *gridColSize)
{
    int gridNum;

    gridNum = 0;
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridColSize[row]; col++) {
            if (grid[row][col] == '1') {
                dfs(grid, gridSize, gridColSize, row, col);
                gridNum++;
            }
        }
    }
    return gridNum;
}
```