### 解题思路
深度优先遍历

### 代码

```c
void dfs(char** grid, int gridSize, int gridColSize, int i, int j) 
{
    //先把陆地变成海洋
    *(*(grid + i) + j) = 48;
    //如果上边是陆地
    if ((i - 1 >= 0) && (*(*(grid + i - 1) + j) == 49)) {
        dfs(grid, gridSize, gridColSize, i - 1, j);
    }
    //如果下边是陆地
    if ((i + 1 <= (gridSize - 1)) && (*(*(grid + i + 1) + j) == 49)) {
        dfs(grid, gridSize, gridColSize, i + 1, j);
    }
    //如果左边是陆地
    if ((j - 1 >= 0) && (*(*(grid + i) + j - 1) == 49)) {
        dfs(grid, gridSize, gridColSize, i, j - 1);
    }
    //如果右边是陆地
    if ((j + 1 <= (gridColSize - 1)) && (*(*(grid + i) + j + 1) == 49)) {
        dfs(grid, gridSize, gridColSize, i, j + 1);
    }
    return;
}
//数组中放的是字符1,0，因此转换为ascii
int numIslands(char** grid, int gridSize, int* gridColSize){
    int numLands = 0;
    if ((0 == gridSize) || (0 == *gridColSize) || (NULL == grid) || (NULL == *grid)) {
        return 0;
    }
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            //如果遇到了陆地，深度优先遍历
            if (*(*(grid + i) + j) == 49) {
                dfs(grid, gridSize, *gridColSize, i, j);
                numLands ++;
            }
        }
    }
    return numLands;
}
```