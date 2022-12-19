### 解题思路
纯C 深度优先

### 代码

```c
static void dfs(char** grid, int gridSize, int* gridColSize, int row, int col)
{
    if (row < 0 || row >= gridSize || col < 0 || col >= *gridColSize || '0' == grid[row][col])
    {
        return ;
    }

    grid[row][col] = '0'; // 对岛部分清零

    dfs(grid, gridSize, gridColSize, row + 1, col);
    dfs(grid, gridSize, gridColSize, row - 1, col);
    dfs(grid, gridSize, gridColSize, row, col + 1);
    dfs(grid, gridSize, gridColSize, row, col - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (NULL == grid || 0 == gridSize || 0 == *gridColSize)
    {
        return 0;
    }

    int row = 0;
    int col = 0;
    int res = 0;

    for (; row <= gridSize - 1; row++)
    {
        for (col = 0; col <= *gridColSize - 1; col++)
        {
            res += grid[row][col] - '0';
            dfs(grid, gridSize, gridColSize, row, col); // 对岛其余部分清零
        }
    }

    return res;
}
```