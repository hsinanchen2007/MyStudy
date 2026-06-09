### 解题思路
v个立方体表面积等于4v+2，两个相邻的三维体表面积等于它们各自的表面积减去共同面的个数*2，遍历数组元素，因为四个方向都有可能相邻，为避免重复相减，每次值检测上和右是否有相邻。

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int area=0;
    int row = gridSize,col = *gridColSize;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j] == 0)
                continue;
            else
            {
                int v=grid[i][j];
                int up =0,right = 0;
                if(i-1>=0&&grid[i-1][j])
                    up=grid[i-1][j]<=v?grid[i-1][j]:v;
                if(j+1<col&&grid[i][j+1])
                    right=grid[i][j+1]<=v?grid[i][j+1]:v;
                 area+=4*v+2-up*2-right*2;
            }
        }
    }
    return area;
}
```