思路：
表面积=所有正方体表面积-接触面个数*2
接触面=（本层个数-1）*2+四个方向相邻接触面；
相邻接触面=较少方块的个数。
```
int min(int a, int b){
    return a<b?a:b;
}
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int all = 0;
    int more = 0;
    for(i = 0;i < gridSize;i++){
        for(j = 0;j < gridColSize[i];j++){
            all +=grid[i][j];
            if(grid[i][j]>0){
                more+=(grid[i][j]-1)*2;
            }
            if(i-1>=0){
                more+=min(grid[i-1][j],grid[i][j]);
            }
            if(i+1<gridSize){
                more+=min(grid[i+1][j],grid[i][j]);
            }
            if(j-1>=0){
                more+=min(grid[i][j-1],grid[i][j]);
            }
            if(j+1<gridColSize[i]){
                more+=min(grid[i][j+1],grid[i][j]);
            }
        }
    }
    return all*6-more;
}
```
![image.png](https://pic.leetcode-cn.com/a32ede7fdb7e6d7b3e280f6eca7ae31339f61b453a98dc666fb868bbe9683528-image.png)


