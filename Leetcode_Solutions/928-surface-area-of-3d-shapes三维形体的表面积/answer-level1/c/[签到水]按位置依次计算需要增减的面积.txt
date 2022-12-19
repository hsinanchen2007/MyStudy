代码如下，思路见注释
```
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i,j,sum=0;
    # 遍历图
    for(i=0;i<gridSize;i++)
        for(j=0;j<gridColSize[i];j++){
            # 当前位置的方块若为零，则新增面积为零，否则加上这一幢的完整的面积
            sum += (grid[i][j]>0)?(grid[i][j]*4+2):0;
            //printf("\n%d\n",sum);
            # 若上邻居存在，减去彼此之间最小高度。不需要两倍，因为在遍历 邻居 的时候也减去这个面积了。
            if((i-1)>=0) sum-=(grid[i-1][j]>grid[i][j])?grid[i][j]:grid[i-1][j];
            //printf("上%d",sum);
            # 同上
            if((i+1)<gridSize) sum-=(grid[i+1][j]>grid[i][j])?grid[i][j]:grid[i+1][j];
            //printf("下%d",sum);
            if((j-1)>=0) sum-=(grid[i][j-1]>grid[i][j])?grid[i][j]:grid[i][j-1];
            //printf("左%d",sum);
            if((j+1)<gridColSize[i]) sum-=(grid[i][j+1]>grid[i][j])?grid[i][j]:grid[i][j+1];
            //printf("右%d",sum);
        }
    return sum;
}
```