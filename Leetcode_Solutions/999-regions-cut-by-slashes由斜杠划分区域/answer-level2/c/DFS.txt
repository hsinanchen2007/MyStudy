### 解题思路
参考了楼上大牛的思路，开始看到这道题完全懵逼。
1.将线段分解成3 * 3的小网格，初始化好“/”和“\\”；
2.DFS求解全0的联通区域个数；

### 代码

```c
int **initGrid(char ** grid, int gridSize) {
    int **newGrid = (int **)malloc(sizeof(int *) * (gridSize * 3));
    int i;
    int j;
    for (i = 0 ; i < gridSize * 3; i++) {
        int *gridcol = (int *)malloc(sizeof(int) * (gridSize * 3));
        memset(gridcol, 0 ,sizeof(int) * (gridSize * 3));
        newGrid[i] = gridcol;
    }

    for (i = 0 ; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            if (grid[i][j] == '/') {
                newGrid[3 * i][3 * j + 2] = 1;
                newGrid[3 * i + 1][3 * j + 1] = 1;
                newGrid[3 * i + 2][3 * j] = 1;
            }
            if (grid[i][j] == '\\') {
                newGrid[3 * i][3 * j] = 1;
                newGrid[3 * i + 1][3 * j + 1] = 1;
                newGrid[3 * i + 2][3 * j + 2] = 1;
            }
        }
    }
    return newGrid;
}
void findRrgions(int **newGrid, int gridSize, int i ,int j){
    if (i == gridSize || i < 0)
        return;
    if (j == gridSize || j < 0)
        return;
    if (newGrid[i][j] == 0) {
        newGrid[i][j] = 1;
        findRrgions(newGrid,gridSize, i + 1,j);
        findRrgions(newGrid, gridSize, i - 1,j);
        findRrgions(newGrid, gridSize, i, j + 1);
        findRrgions(newGrid, gridSize, i, j - 1);
    }
}
int regionsBySlashes(char ** grid, int gridSize){

    int **newGrid = initGrid(grid, gridSize);
    int regions =0;
    int i, j;
    for (i = 0; i < 3 * gridSize; i++) {
        for(j = 0; j < 3 * gridSize; j++) {
            if (newGrid[i][j] == 0) {
                findRrgions(newGrid, 3 * gridSize, i ,j);
                regions++;
            }
        }
    }
    //free;
    for (i=0; i < gridSize * 3; i+=) {
        free(newGrid[i]);
    }
    free(newGrid);
    return regions;
}
```