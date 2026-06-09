### 解题思路
是不是用时间换取了空间

### 代码

```c
int maxDistance(int** grid, int gridSize, int* gridColSize){
    int sum=0,area=1,land=1;
    for(int i=0;i<gridSize;i++)
        for(int j=0;j<*gridColSize;j++)
            sum+=grid[i][j];
    if(sum==gridSize*(*gridColSize)||sum==0)
        return -1;
    sum=0;   
    while(1){
        land++;
        for(int i=0;i<gridSize;i++){
            for(int j=0;j<*gridColSize;j++){
                if(grid[i][j]==area){
                    if(i > 0 && grid[i - 1][j]==0)
                    grid[i - 1][j]=land;
                    if (i < gridSize - 1 && grid[i + 1][j]==0)
                    grid[i + 1][j]=land;
                    if(j > 0&& grid[i][j - 1]==0)
                    grid[i][j - 1]=land;
                    if (j < *gridColSize - 1 && grid[i][j + 1]==0)
                    grid[i][j + 1]=land;
                }
                sum=sum>grid[i][j]?sum:grid[i][j];                        
            }
        }
        area=land;
        if(area>(gridSize-1)*2)
            break;
    }
    return sum-1;
}
```