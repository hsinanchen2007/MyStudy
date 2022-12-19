### 解题思路
遇到‘1’，进行计数，同时将该岛屿联通的1清零

### 代码

```c
void clearIsland(char** grid, int gridSize, int colsize, int i, int j){
    if(i < 0 || i == gridSize || j < 0 || j == colsize || grid[i][j] == '0')
        return;
    grid[i][j] = '0';
    int direct[4][2] = {0,1,0,-1,1,0,-1,0};
    for(int k = 0; k < 4; ++k)
        clearIsland(grid, gridSize, colsize, i + direct[k][0], j + direct[k][1]);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(grid == NULL || gridColSize == NULL)
        return 0;
    int result = 0;
    for(int i = 0; i < gridSize; ++i){
        for(int j = 0; j < *gridColSize; ++j){
            if(grid[i][j] == '1') {
                ++result;
                clearIsland(grid, gridSize, *gridColSize, i, j);
            }
        }
    }
    return result;
}
```