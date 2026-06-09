### 解题思路
每一个立方体有6个面，则
                **总面数=6*总立方体数；**
每有两个立方体相邻则构成一个连接点，每一个连接点消耗两个面，则：
                **总消耗数=2*总连接点数**
所以：
                **总表面积=总面数-总消耗数**
因此，只需统计立方体数和连接点数即可。
### 代码

```c
#define min(a,b) a<b?a:b
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int linkpoint=0,cubenum=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
                if(grid[i][j]!=0){
                        cubenum+=grid[i][j];
                            linkpoint+=grid[i][j]-1;
                            if(i==0 && j>0){
                                if(grid[i][j-1]!=0){
                                    linkpoint+=min(grid[i][j-1],grid[i][j]);
                                }
                            }
                            if(j==0 && i>0){
                                if(grid[i-1][j]!=0){
                                    linkpoint+=min(grid[i-1][j],grid[i][j]);
                                }
                            }
                            if(i>0 && j>0){
                                if(grid[i-1][j]!=0){
                                    linkpoint+=min(grid[i-1][j],grid[i][j]);
                                }                
                                if(grid[i][j-1]!=0){
                                    linkpoint+=min(grid[i][j-1],grid[i][j]);
                                }
                            }                
                    }                    
                }
                
    }
    return cubenum*6-linkpoint*2;
}
```