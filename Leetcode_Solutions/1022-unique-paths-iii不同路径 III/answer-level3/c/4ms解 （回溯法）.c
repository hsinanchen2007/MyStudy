```
int N=0,m;
void ss(int x,int y,int** grid,int n, int gridSize, int* gridColSize){
    if(n==N){
        if((x+1<gridSize&&grid[x+1][y]==2)||(y-1>=0&&grid[x][y-1]==2)||(x-1>=0&&grid[x-1][y]==2)||(y+1<gridColSize[0]&&grid[x][y+1]==2))
            m++;
        return;
    }
    if(x+1<gridSize&&grid[x+1][y]==0){
        grid[x+1][y]=1;
        ss(x+1,y,grid,n+1,gridSize,gridColSize);
        grid[x+1][y]=0;
    }
    if(y-1>=0&&grid[x][y-1]==0){
        grid[x][y-1]=1;
        ss(x,y-1,grid,n+1,gridSize,gridColSize);
        grid[x][y-1]=0;
    }
    if(x-1>=0&&grid[x-1][y]==0){
        grid[x-1][y]=1;
        ss(x-1,y,grid,n+1,gridSize,gridColSize);
        grid[x-1][y]=0;
    }
    if(y+1<gridColSize[0]&&grid[x][y+1]==0){
        grid[x][y+1]=1;
        ss(x,y+1,grid,n+1,gridSize,gridColSize);
        grid[x][y+1]=0;
    }
}
int uniquePathsIII(int** grid, int gridSize, int* gridColSize){
    N=0;
    m=0;
    int x,y;
    for(int i=0;i<gridSize;i++)
        for(int j=0;j<gridColSize[0];j++)
            if(grid[i][j]==0)
                N++;
            else if(grid[i][j]==1){
                x=i;
                y=j;
            }
    ss(x,y,grid,0,gridSize,gridColSize);
    return m;
}
```
