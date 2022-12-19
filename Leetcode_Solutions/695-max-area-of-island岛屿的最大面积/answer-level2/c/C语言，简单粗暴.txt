遍历整个数组，找到一个1，然后就开始从这个1开始搜索连成一片的岛屿，如果岛屿面积是目前最大就保存。
```
//全局变量，统计当前岛屿面积
int count = 0;
//从第一个1开始搜索四周的岛屿
void SEARCH(int **grid , int i, int j, int gridSize, int *gridColSize){
    if (i - 1 >=0 && grid[i - 1][j] == 1)
    {
        count++;
        grid[i - 1][j] = 2;
        SEARCH(grid,i - 1,j,gridSize,gridColSize);
    }
    if (j - 1 >= 0 && grid[i][j - 1] == 1)
    {
        count++;
        grid[i][j - 1] = 2;
        SEARCH(grid,i,j - 1,gridSize,gridColSize);
    }
    if (i + 1 < gridSize && grid[i + 1][j] == 1)
    {
        count++;
        grid[i + 1][j] = 2;
        SEARCH( grid, i + 1, j, gridSize, gridColSize);
    }
    if (j + 1 < *gridColSize && grid[i][j + 1] == 1)
    {
        count++;
        grid[i][j + 1] = 2;
        SEARCH(grid,i,j + 1,gridSize,gridColSize);
    }
    
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int max = 0;
    for (int i = 0; i < gridSize;i++)
    {
        for ( int j = 0; j < *gridColSize; j++) 
        {
            if (grid[i][j] == 1)
            {
                count++;
                //将陆地位置标记为2，避免重复
                grid[i][j] = 2;
                SEARCH(grid,i,j,gridSize,gridColSize);
                if (count > max)
                {
                    max = count;
                }
            }
            count = 0;
        }
    }
    return max;
}
```
