### 解题思路
  从上下来看，因为方块一定是连续堆叠的，所以从上向下投影的影子面积就是整体上面和下面的面积，
但是从侧面来看就不能这样简单的计算，从侧面的截面来看，如果截面是一个峰型，比如12321，可以用投影法计算   该截面的两边的表面积为3*2=6，但如果截面是一个沟型，比如32123，如果用投影法计算，只计算了最高点的投影，没有计算到沟内两边的表面积，所以对侧面的表面积计算要把每一个坡面算进去，
  我们可以计算每一个方向（从前向后或者从左向右）的面积时，可以把该方向的侧面切成一片一片的，计算每一片两边的表面积加入结果中。
  对每一片的两边面积计算可以用每两个相邻的格子间的差的绝对值的累加来计算，对两侧的格子要另外加上两边外侧的面积，比如一个侧面的数据是120435，该侧面两边方向的面积s=1+|2-1|+|0-2|+|4-0|+|3-4|+|5-3|+5
  可以用这个方法分别遍历计算前后和左右两个方向的面积，上下的面积则采用投影法来计算

### 代码

```c
int abs(int n)
{
    return n>0?n:0-n;
}

int surfaceArea(int** grid, int gridSize, int* gridColSize){
   
    // for(int i=0;i<gridSize;i++)
    // {
    //     for(int j=0;j<*gridColSize;j++)
    //     {
    //         printf("%d ",grid[i][j]);
    //     }
    //     printf("\n");
    // }
   
    int side1=0;
    int bottom=0;
    
    for(int i=0;i<gridSize;i++)
    {
        side1+=grid[i][0];
        bottom+=grid[i][0]>0?1:0;
        for(int j=1;j<*gridColSize;j++)
        {
            bottom+=grid[i][j]>0?1:0;
            side1+=abs(grid[i][j]-grid[i][j-1]);
        }
        side1+=grid[i][*gridColSize-1];
    }
    
    int side2=0;
    for(int i=0;i<*gridColSize;i++)
    {
        side2+=grid[0][i];
        for(int j=1;j<gridSize;j++)
        {
            side2+=abs(grid[j][i]-grid[j-1][i]);
        }
        side2+=grid[gridSize-1][i];
    }
   // printf("s1=%d s2=%d b=%d ",side1,side2,bottom);
    return side2+side1+bottom*2;
}
```