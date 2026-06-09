### 解题思路
1:在遍历二维数组的途中，如果碰到“陆地（字符1）”，调dfs深度搜索，计数器加1，表示找到了一块陆地。
2:调用dfs深度搜索，如果搜索到‘陆地’，将其置为海洋，此题与第130题很相似；

### 代码

```c
void dfs(char**grid,int i,int j,int m,int n){
    if(i>=0&&i<m&&j>=0&&j<n&&grid[i][j]=='1')
    grid[i][j]='0';
    else
    return;
    dfs(grid,i-1,j,m,n);
    dfs(grid,i,j+1,m,n);
    dfs(grid,i+1,j,m,n);
    dfs(grid,i,j-1,m,n);
}
int numIslands(char** grid, int gridSize, int* gridColSize){
int i,j,count=0;
if(grid==NULL||gridSize==0||gridColSize==NULL)
return 0;
int colsize=gridColSize[0];
for(i=0;i<gridSize;i++){
    for(j=0;j<colsize;j++){
        if(grid[i][j]=='1'){
            dfs(grid,i,j,gridSize,colsize);
            count++;
        }
    }
}
return count;
}
```