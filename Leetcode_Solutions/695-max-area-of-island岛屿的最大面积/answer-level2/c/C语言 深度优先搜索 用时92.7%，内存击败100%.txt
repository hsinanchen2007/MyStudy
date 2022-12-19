### 解题思路
深度优先搜索，置为1-0，统计各个启动深度优先搜索岛屿数量，取最大值即可

### 代码

```c
void dfs(int** grid, int maxRow, int maxCol, int curRow, int curCol, int* curCnt, int* maxCnt)
{
    grid[curRow][curCol] = 0;
    (*curCnt)++;
    if (*curCnt >= *maxCnt) {
        *maxCnt = *curCnt;
    }
    
    if (curRow -1 >= 0 && grid[curRow - 1][curCol] == 1) {
        dfs(grid, maxRow, maxCol, curRow - 1, curCol, curCnt, maxCnt);
    }
    if (curRow + 1 < maxRow && grid[curRow + 1][curCol] == 1) {
        dfs(grid, maxRow, maxCol, curRow + 1, curCol, curCnt, maxCnt);
    }
    if (curCol - 1 >= 0 && grid[curRow][curCol - 1] == 1) {
        dfs(grid, maxRow, maxCol, curRow, curCol - 1, curCnt, maxCnt);
    }
    if (curCol + 1 < maxCol && grid[curRow][curCol + 1] == 1) {
        dfs(grid, maxRow, maxCol, curRow, curCol + 1, curCnt, maxCnt);
    }
}

// 每次把1置位，统计最大岛屿数
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if (gridSize == 0) {
        return 0;
    }

    int maxRow = gridSize;
    int maxCol = *gridColSize;
    int maxCnt = 0;
    int curCnt = 0;
    int rowIdx;
    int colIdx;
    for (rowIdx = 0; rowIdx < maxRow; rowIdx++) {
        for (colIdx = 0; colIdx < maxCol; colIdx++) {
            if (grid[rowIdx][colIdx] == 1) {
                dfs(grid, maxRow, maxCol, rowIdx, colIdx, &curCnt, &maxCnt);
            }
            curCnt = 0;
        }
    }
    return maxCnt;
}
```