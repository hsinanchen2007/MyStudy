开始想到暴力破解，本来想分类，但是分类写起来太麻烦了。不如写个函数来直接判断岛屿是否存在，对于临近四个岛屿粗暴判断；
```
int exist(int gridSize, int gridColSize,int i,int j){
    if(i>=0&&i<gridSize&&j>=0&&j<gridColSize) return 1;
    return 0;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int vex=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
            if(grid[i][j]==1) {
                vex+=4;
                if(exist(gridSize,* gridColSize,i-1,j)&&grid[i-1][j]==1) vex--;
                if(exist(gridSize,* gridColSize,i+1,j)&&grid[i+1][j]==1) vex--;
                if(exist(gridSize,* gridColSize,i,j-1)&&grid[i][j-1]==1) vex--;
                if(exist(gridSize,* gridColSize,i,j+1)&&grid[i][j+1]==1) vex--;
            }      
            
        }
    }
    return vex;
}

```
