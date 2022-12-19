### 解题思路
基于62题思路：
每次只能从上、从左来，每次将这两个方向中最小的，赋给新位置

### 代码

```c
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int **route_amount=(int**)malloc(sizeof(int*)*gridSize);
    for(int i=0; i<gridSize; i++)
    {
        route_amount[i]=(int*)malloc(sizeof(int)*(*gridColSize));
        memset(route_amount[i],0x00,sizeof(int)*(*gridColSize));
    }
    route_amount[0][0]=grid[0][0];
    for(int i=1;i<gridSize;i++) route_amount[i][0]=route_amount[i-1][0]+grid[i][0];//只能从上面来
    for(int i=1;i<*gridColSize;i++) route_amount[0][i]=route_amount[0][i-1]+grid[0][i];//只能从左面来
    for(int i=1;i<gridSize;i++)
    {
        for(int j=1;j<*gridColSize;j++)
        {
            route_amount[i][j]=((route_amount[i-1][j]+grid[i][j])>(route_amount[i][j-1]+grid[i][j]))?(route_amount[i][j-1]+grid[i][j]):(route_amount[i-1][j]+grid[i][j]);
        }
    }
    return route_amount[gridSize-1][*gridColSize-1];
}
```