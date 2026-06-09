### 解题思路
逐个方块进行扫描，减去三个方向的重合面

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i = 0,j = 0,k = 0,area = 0;
    for(i = 0;i<gridSize;i++)
    {
        for(j = 0;j<*gridColSize;j++)
        {
            for(k = 0;k<grid[i][j];k++)
            {
                area += 6;
                if(k > 0)//当一个格子不止1个立方体时
                {
                    area -= 2;//减去下方两个重合面
                }
                if(i>0&&grid[i-1][j]>k)
                {
                    area -= 2;//减去左面两个重合面
                }
                if(j>0&&grid[i][j-1]>k)
                {
                    area -= 2;//减去前面两个重合面
                }
            }
        }
    }
    return area;

}
```