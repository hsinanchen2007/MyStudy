原来return;可以和for语句在同一行，这样就避免了for语句后面必须再return一句的尴尬
```
int minPathSum(int** grid, int gridSize, int* gridColSize){for(int i=0,j=1;i<gridSize;j++)if(j==*gridColSize&&(++i)!=gridSize)grid[i][j=0]+=grid[i-1][0];else if(i!=gridSize)if(i!=0){grid[i][j]+=grid[i][j-1]>grid[i-1][j]?grid[i-1][j]:grid[i][j-1];}else grid[0][j]+=grid[0][j-1];else return grid[gridSize-1][*gridColSize-1];return;}
```
