### 解题思路
此处撰写解题思路

### 代码

```c
int search(int **grid, int i, int j,int s, int c){
    int sum=0,n1=0,n2=0,n3=0,n4=0;
    if(grid[i][j]==1){
        grid[i][j]=0;
        if(i!=0) n1=search(grid,i-1,j,s,c);
        if(i!=s-1) n2=search(grid,i+1,j,s,c);
        if(j!=0) n3=search(grid,i,j-1,s,c);
        if(j!=c-1) n4=search(grid,i,j+1,s,c);
        sum=1+n1+n2+n3+n4;
        return sum;
    }
    else return 0;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
int max=0,n;
for(int i=0; i<=gridSize-1; i++)
 for(int j=0; j<=gridColSize[0]-1; j++){
     n=search(grid,i,j,gridSize,gridColSize[0]);
     if(n>max) max=n;
 }
return max;
}
```