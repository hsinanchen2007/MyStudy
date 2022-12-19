
/*****************************************************************************************/
/*
思路：
    1、写一个查询上下左右的函数用于获取是否相连和获取面积
    2、对查询过的陆地用其他值（0,1除外）代替，避免重复查询,保证只查询一次
    3、难点，多个分支嵌套
*/



 //int max=0;/*最大值,为什么全局变量不能初始化为0呢？*/
/*行，列，grid,gridColSise*/
int get_land(int i,int j,int** grid,int* gridColSize,int gridSize)
{
    int land=1;
    if(i>0) /*上，行有元素*/
    {
        if (gridColSize[i-1]>j) /*上行j列有值*/
            if (grid[i-1][j]==1)/*有陆地*/
            {
                grid[i-1][j] = 2;
                land +=get_land(i-1,j,grid,gridColSize,gridSize);
                //printf("**up**i=%d,j=%d,land=%d\n",i,j,land);
            }
    }
    if(i+1<gridSize)/*下*/
    {
        if (gridColSize[i+1]>j) /*下行j列有值*/
            if(grid[i+1][j]==1)/*有陆地*/
            {
                grid[i+1][j] = 2;
                land +=get_land(i+1,j,grid,gridColSize,gridSize);
                //printf("**down**i=%d,j=%d,land=%d\n",i,j,land);
            }
    }
    if(j>0)/*左,左侧有元素*/
    {
        if(grid[i][j-1]==1)/*有陆地*/
        {
            grid[i][j-1] = 2;
            land +=get_land(i,j-1,grid,gridColSize,gridSize);
            //printf("**left**i=%d,j=%d,land=%d\n",i,j,land);
        }
    }
    if(j+1 < gridColSize[i])/*右,右侧有元素*/
    {
        if(grid[i][j+1]==1)/*有陆地*/
        {
            grid[i][j+1] = 2;
            land +=get_land(i,j+1,grid,gridColSize,gridSize);
            //printf("**right**i=%d,j=%d,land=%d\n",i,j,land);
        }
    }
    //printf("**end**i=%d,j=%d,land=%d\n",i,j,land);
    return land;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
    int i,j;
    int area=0;
    int max=0;/*最大值,为什么全局变量不能初始化为0呢？*/
    for( i=0;i<gridSize;i++)/*遍历每个数*/
    {
        for( j=0;j<gridColSize[i];j++)
        {
            if(1==grid[i][j])
            {
                //printf("start:***max=%d****\n",max);
                //printf("i=%d,j=%d\n",i,j);
                grid[i][j] = 2;
                area=get_land(i,j,grid,gridColSize,gridSize);
                //printf("end**area=%d**max=%d****\n\n",area,max);
                if(area>max)
                    max=area;
            }
        }
    }
    return  max;
}

```