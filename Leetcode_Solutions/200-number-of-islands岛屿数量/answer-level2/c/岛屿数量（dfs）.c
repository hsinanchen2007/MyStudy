# 思路
当碰见地形为1时，于是就深度搜索，将1变为0，表示此地已经搜索过了，否则就会无限递归下去。每次将岛屿数量+1，最终就会得到所有的岛屿数量。
# 代码
```
int numIslands(char** grid, int gridSize, int* gridColSize){
    // isLandCount
    int count = 0;
    int i = 0;
    int j = 0;
    
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                count++;
                solve(grid, gridSize, gridColSize, i, j, count);
            }
        }
    }
    
    
    return count;
}

void solve(char** grid, int gridSize, int* gridColSize, int i, int j, int count) {
    if (i<0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    // up
    solve(grid, gridSize, gridColSize, i-1, j, count);
    // down
    solve(grid, gridSize, gridColSize, i+1, j, count);  
    // left
    solve(grid, gridSize, gridColSize, i, j-1, count);
    // right
    solve(grid, gridSize, gridColSize, i, j+1, count); 

}
```
