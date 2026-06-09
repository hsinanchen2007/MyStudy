### 解题思路
反正这种就是bfs或者dfs, 都可以, 遍历了就行了
一个比较取巧的技巧是, 当我们在某一个1的时候, 在递归周围的时候, 我们可以把当前设置为0, 避免再次使用到这个值

### 代码

```c
void recursive(int**grid, int x, int y, int *area, int row_len, int col_len){
    grid[x][y] = 0;
    (*area)++;
    int top_x = x-1;
    int btm_x = x+1;
    int left_y = y-1;
    int right_y = y+1;
    if(top_x>=0&&grid[top_x][y]==1) recursive(grid, top_x, y, area, row_len, col_len);
    if(btm_x<row_len&&grid[btm_x][y]==1) recursive(grid, btm_x, y, area, row_len, col_len);
    if(left_y>=0&&grid[x][left_y]==1) recursive(grid, x, left_y, area, row_len, col_len);
    if(right_y<col_len&&grid[x][right_y]==1) recursive(grid, x, right_y, area, row_len, col_len);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int maxArea = 0;
    int currentArea = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if(grid[i][j]==1){
                // 递归周围
                recursive(grid, i, j, &currentArea, gridSize, gridColSize[0]);
                maxArea = maxArea>currentArea?maxArea:currentArea;
                currentArea = 0;
            }
        }
    }
    return maxArea;
}
```