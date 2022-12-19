### 解题思路
考虑表面积的增减：在任意处增加方块，表面积加六，如果有接触，每有一面接触，表面积减二。
因此，先计算竖直方向上的柱体表面积，再考虑四面是否有接触，把接触的面减掉就好啦

### 代码

```c
#define min(a,b) a>b?b:a
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    if(gridSize==0) return 0;
    int i,j,surface=0;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j]==0) continue;
            surface=6*grid[i][j]-2*(grid[i][j]-1)+surface;
            if(i>0) surface-=min(grid[i-1][j],grid[i][j]);
            if(j>0) surface-=min(grid[i][j-1],grid[i][j]);
            if(i<gridSize-1) surface-=min(grid[i+1][j],grid[i][j]);
            if(j<gridColSize[i]-1) surface-=min(grid[i][j+1],grid[i][j]);
        }
    }
    return surface;
}
```