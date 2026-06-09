### 解题思路
例：[[1,2],[3,4]]
表示二维数组：
1 2
3 4
在空间中排列位置：
1个正方体 2个正方体
3个正方体 4个正方体
理解到这里接下来就是运用空间几何求面积的方法了
xy轴投影=二维数组中非0元素的个数*1；
xz轴投影=每列最大元素之和*1;
yz轴投影=每行最大元素之和*1;

### 代码

```c
int projectionArea(int** grid, int gridSize, int* gridColSize){
        int i,j,xy=0,xz=0,yz=0,cmax,rmax,col=*gridColSize;
        for(j=0;j<col;j++){
            cmax=0;
            rmax=0;
            for(i=0;i<col;i++){
                 if(grid[i][j]>cmax)cmax=grid[i][j];
                 if(grid[j][i]>rmax)rmax=grid[j][i];
                 if(grid[i][j]!=0)xy++;
                    }
            xz+=cmax;
            yz+=rmax ;   
        }
        
    return xy+yz+xz;    
}
```