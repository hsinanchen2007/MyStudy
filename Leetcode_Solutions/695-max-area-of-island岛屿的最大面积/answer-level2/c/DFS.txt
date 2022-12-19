### 解题思路
此处撰写解题思路

### 代码

```c
void DFS(int**grid,int i,int j,int m,int n,int*sum)
{
    if(i<0||i>=m||j<0||j>=n||grid[i][j]!=1)
    return;
    (*sum)++;
    grid[i][j]=2;    //做标记，这个点踩过了
    DFS(grid,i-1,j,m,n,sum);
    DFS(grid,i+1,j,m,n,sum);
    DFS(grid,i,j-1,m,n,sum);
    DFS(grid,i,j+1,m,n,sum);
    return;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
int i,j,m,n,max=0,t=0;
int*sum=&t;
if(gridSize==0||gridColSize[0]==0)
return 0;
m=gridSize;n=gridColSize[0];
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        if(grid[i][j]==1){
            (*sum)=0;
            DFS(grid,i,j,m,n,sum);
            if(max<(*sum))
            max=*sum;
        }
    }
}
return max;
}
```