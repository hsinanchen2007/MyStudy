### 解题思路
1.遍历到一个为1的点，以此点为基础开始遍历，将面积+1，同时将此点标记为2，后面遇到2便不在遍历；
2.遍历完成后，跟最大面积比对；
3.输出最大面积；

### 代码
```c
void dfs(int **grid, int gridSize, int *gridColSize, int x, int y, int *areaOfIsLand)
{
    *areaOfIsLand += 1;
    grid[x][y] = 2;
    for (int i = -1; i <= 1; i++) {
        if (i == 0) {
            continue;
        }

        if (((x+i) >= 0) && ((x+i) < gridSize) && (grid[x+i][y] == 1)) {
            
            dfs(grid, gridSize, gridColSize, x+i, y, areaOfIsLand);
        }
    }

    for (int i = -1; i <= 1; i++) {
        if (i == 0) {
            continue;
        }

        if (((y+i) >= 0) && ((y+i) < gridColSize[x]) && (grid[x][y+i] == 1)) {
            dfs(grid, gridSize, gridColSize, x, y+i, areaOfIsLand);
        }
    }

}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int areaOfIsLand = 0;
    int maxAreaOfIsland = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            areaOfIsLand = 0;
            if (grid[i][j] == 1) {
                dfs(grid, gridSize, gridColSize, i, j, &areaOfIsLand);
            }

            maxAreaOfIsland = (maxAreaOfIsland > areaOfIsLand) ? maxAreaOfIsland : areaOfIsLand;
        }
    }
    return maxAreaOfIsland;
}
```