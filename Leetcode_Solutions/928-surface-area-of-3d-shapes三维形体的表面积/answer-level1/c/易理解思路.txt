### 解题思路
先统计本块，再统计左侧，最后上侧。

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int count=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            count+=grid[i][j]*6; //先加好
            if(grid[i][j]>1) count-=(grid[i][j]-1)*2;//减本块的重叠
            if(j>0){
                if(grid[i][j-1]!=0){//减左侧重叠
                    int min=0;
                    min=grid[i][j-1]<grid[i][j]?grid[i][j-1]:grid[i][j];
                    count-=min*2;
                }    
            }
            if(i>0){
                if(grid[i-1][j]!=0){//减h上侧重叠
                    int min=0;
                    min=grid[i-1][j]<grid[i][j]?grid[i-1][j]:grid[i][j];
                    count-=min*2;
                }
            }
        }
    }
    return count;    
}
```