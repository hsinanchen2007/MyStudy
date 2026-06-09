### 解题思路
侧面每有高低起伏，就会露出表面积
顶和低只要有方块，就有2个表面积。默认竖着一列内部不存在真空哈，有重力的。
还得记得把最外边一圈的表面积加上
这大概是最笨的方法了，哈哈

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int row=0,col=0,area=0;

    //每一行，相邻两列求差的绝对值之和，代表左右方向的表面积
    for(row=0; row<gridSize; row++)
    {
        for(col=0; col<*gridColSize-1; col++)
        {
            area += abs( *(*(grid+row)+col) - *(*(grid+row)+col+1) );
        }
        //当前行最左和最右两侧露出的表面积
        area += grid[row][0];
        area += grid[row][*gridColSize-1];
    }

    //每一列，相邻两行求差的绝对值之和，代表上下方向的表面积
    for(col=0; col<*gridColSize; col++)
    {
        for(row=0; row<gridSize-1; row++)
        {
            area += abs( *(*(grid+row)+col) - *(*(grid+row+1)+col) );
        }
        //当前列最上和最下边露出的表面积
        area += grid[0][col];
        area += grid[gridSize-1][col];
    }

    //顶底表面积为所有不为零坐标（存在方块）之和*2
    for(row=0; row<gridSize; row++)
    {
        for(col=0; col<*gridColSize; col++)
        {
            if( *(*(grid+row)+col) != 0)
            {
                area += 2;
            }
        }
    }

    return area;
}
```