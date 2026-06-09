![image.png](https://pic.leetcode-cn.com/2f8dcb4c1f6c7c7e262000973b7b52adb023dd577d0dde5435339beff98d652f-image.png)
![image.png](https://pic.leetcode-cn.com/bed1085455ca287ff1893ff6101b3158924f4f02a05f4030e724f51b4de58457-image.png)

# **代码：**
```
int projectionArea(int** grid, int gridSize, int* gridColSize){
    int i,j,
        total = 0,
        frontmax = 0,
        *sidemax = calloc(*gridColSize,sizeof(int));

    for(i = 0; i < gridSize;i++){
        frontmax = 0;
        for(j = 0; j < *gridColSize;j++){
            total += (grid[i][j] > 0);
            if(grid[i][j] > frontmax){
                frontmax = grid[i][j];
            }
            if(grid[i][j] > sidemax[j]){
                sidemax[j] = grid[i][j];
            }            
        }
        total += frontmax;
    }

    for(i = 0; i < *gridColSize;i++){
        total += sidemax[i];
    }
    free(sidemax);
    return total;
}
```
