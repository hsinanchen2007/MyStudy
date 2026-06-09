### 解题思路
1、依次遍历数组，找到没有被遍历且是陆地的点，四个方向深度遍历扩展；
2、遍历到陆地，标记下，遇到水停止；
3、遇到遍历过的陆地，跳过；
4、遇到没有遍历过的陆地，表示找到一个岛屿，四个方向深度扩张；

### 代码

```c

int islandNum;
int **map = NULL;
void findIsland(char** grid, int gridSize, int gridColSize, int i, int j)
{
    if (i < 0 || i > gridSize - 1) {
        return;
    }
    if (j < 0 || j > gridColSize - 1) {
        return;
    }
    if(map[i][j] == 1) {
        return;
    }
    if (grid[i][j] == '0') {
        return;
    }

    map[i][j] = 1;
    findIsland(grid, gridSize, gridColSize, i - 1, j);
    findIsland(grid, gridSize, gridColSize, i, j - 1);
    findIsland(grid, gridSize, gridColSize, i + 1, j);
    findIsland(grid, gridSize, gridColSize, i, j + 1);

    return;

}
int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int i = 0;
    int j = 0;
    islandNum = 0;

    if (grid == NULL || gridSize == 0){
        return 0;
    }
    if (gridColSize == NULL || *gridColSize == 0) {
        return 0;
    }

    map = (int **) malloc(gridSize * sizeof(int *));
    for (i = 0; i < gridSize; i++) {
        map[i] = (int *)malloc((gridColSize[i]) * sizeof(int));
        memset(map[i], 0, gridColSize[i] * sizeof(int));
    }
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if(grid[i][j] != '1' || map[i][j] == 1) {
                continue;
            }
            islandNum++;
            findIsland(grid, gridSize, gridColSize[i], i, j);
        }
    }
    for (i = 0; i < gridSize; i ++) {
        free(map[i]);
    }
    free(map);

    return islandNum;
}
```