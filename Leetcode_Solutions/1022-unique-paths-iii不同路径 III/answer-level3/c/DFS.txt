```
int sum;
int di[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int**grid,int m,int n,int count,int**visit,int i,int j){
    if(i<0||j<0||i>=m||j>=n)return;
    if(visit[i][j]==1||grid[i][j]==-1)return;
    if(grid[i][j]==2){
        if(count==0)sum++;
        return;
    } 
    for(int a=0;a<4;a++){
        visit[i][j]=1;
        if(grid[i][j]==0)count--;
        dfs(grid,m,n,count,visit,i+di[a][0],j+di[a][1]);
        visit[i][j]=0;
        if(grid[i][j]==0)count++;
    }
}
int uniquePathsIII(int** grid, int gridSize, int* gridColSize){
    if(gridSize==1&&*gridColSize==1)return 0;
    int m=gridSize,n=*gridColSize,count=0,x,y;
    sum=0;
    int**visit=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        visit[i]=(int*)calloc(n,sizeof(int));
        for(int j=0;j<n;j++){
            if(grid[i][j]==0)count++;
            if(grid[i][j]==1){
                x=i;
                y=j;
            }
        }
    }
    dfs(grid,m,n,count,visit,x,y);
    return sum;
}
```
