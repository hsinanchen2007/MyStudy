典型的动态规划问题：
```c
/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 */

#define Min(x,y) ((x)>(y)?(y):(x))
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i=0,j=0;
    grid[0][0]=grid[0][0];
    for(j=1;j<*gridColSize;j++)
    {
        grid[0][j]=grid[0][j-1]+grid[0][j];
    }
    for(i=1;i<gridSize;i++)
    {
        grid[i][0]=grid[i-1][0]+grid[i][0];
    }
    for(i=1;i<gridSize;i++)
    {
        for(j=1;j<*gridColSize;j++)
        {
            grid[i][j]=Min(grid[i-1][j],grid[i][j-1])+grid[i][j];
        }
    }
    return grid[gridSize-1][*gridColSize-1];
}

```