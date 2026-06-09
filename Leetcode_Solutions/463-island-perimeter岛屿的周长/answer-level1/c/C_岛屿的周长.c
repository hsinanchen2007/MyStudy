### 解题思路
选择所有的岛屿，判断上下左右是否有海洋相邻。
如果想要更简洁的代码，可以扩大地图，在四周再围一圈海洋，就可以不必特殊考虑四个地图四个边四个角上的陆地。

### 代码

```c
int C(int** Grid, int GridSize, int* GridColSize,int Row,int Col)
{
    //坐标不在地图边缘
    if(0<Row&&Row<GridSize-1&&0<Col&&Col<GridColSize[Row]-1)
    {
        int result=0;
        if(Grid[Row-1][Col]==0)++result;
        if(Grid[Row][Col+1]==0)++result;
        if(Grid[Row+1][Col]==0)++result;
        if(Grid[Row][Col-1]==0)++result;
        return result;
    }
    //坐标在地图上边缘
    if(Row==0&&Col!=0&&Col!=GridColSize[Row]-1)
    {
        int result=1;
        if(Grid[Row][Col+1]==0)++result;
        if(Row+1<GridSize&&Grid[Row+1][Col]==0)++result;
        if(Row+1>=GridSize)++result;
        if(Grid[Row][Col-1]==0)++result;
        return result;
    }
    //坐标在地图下边缘
    if(Row==GridSize-1&&Col!=0&&Col!=GridColSize[Row]-1)
    {
        int result=1;
        if(Row-1>=0&&Grid[Row-1][Col]==0)++result;
        if(Row-1<0)++result;
        if(Grid[Row][Col+1]==0)++result;
        if(Grid[Row][Col-1]==0)++result;
        return result;
    }
    //坐标在地图左边缘
    if(Col==0&&Row!=0&&Row!=GridSize-1)
    {
        int result=1;
        if(Grid[Row-1][Col]==0)++result;
        if(Col+1<GridColSize[Row]&&Grid[Row][Col+1]==0)++result;
        if(Col+1>=GridColSize[Row])++result;
        if(Grid[Row+1][Col]==0)++result;
        return result;
    }
    //坐标在地图右边缘
    if(Col==GridColSize[Row]-1&&Row!=0&&Row!=GridSize-1)
    {
        int result=1;
        if(Grid[Row-1][Col]==0)++result;
        if(Grid[Row+1][Col]==0)++result;
        if(Col-1>=0&&Grid[Row][Col-1]==0)++result;
        if(Col-1<0)++result;
        return result;
    }
    //地图左上角
    if(Row==0&&Col==0)
    {
        int result=2;
        if(Col+1<GridColSize[Row]&&Grid[Row][Col+1]==0)++result;
        if(Col+1>=GridColSize[Row])++result;
        if(Row+1<GridSize&&Grid[Row+1][Col]==0)++result;
        if(Row+1>=GridSize)++result;
        return result;
    }
    //地图右上角
    if(Row==0&&Col==GridColSize[Row]-1)
    {
        int result=2;
        if(Row+1<GridSize&&Grid[Row+1][Col]==0)++result;
        if(Row+1>=GridSize)++result;
        if(Col-1>=0&&Grid[Row][Col-1]==0)++result;
        if(Col-1<0)++result;
        return result;
    }
    //地图右下角
    if(Row==GridSize-1&&Col==GridColSize[Row]-1)
    {
        int result=2;
        if(Row-1>=0&&Grid[Row-1][Col]==0)++result;
        if(Row-1<0)++result;
        if(Col-1>=0&&Grid[Row][Col-1]==0)++result;
        if(Col-1<0)++result;
        return result;
    }
    //地图左下角
    if(Row==GridSize-1&&Col==0)
    {
        int result=2;
        if(Row-1>=0&&Grid[Row-1][Col]==0)++result;
        if(Row-1<0)++result;
        if(Col+1<GridColSize[Row]&&Grid[Row][Col+1]==0)++result;
        if(Col+1>=GridColSize[Row])++result;
        return result;
    }
    printf("Wrong(%d,%d)\n",Row,Col);
    return -1;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int result=0;
    for(int row=0;row<gridSize;++row)
        for(int col=0;col<gridColSize[row];++col)
            if(grid[row][col]==1)
                result+=C(grid,gridSize,gridColSize,row,col);
    return result;
}
```