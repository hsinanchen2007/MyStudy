### 解题思路
遍历二位数组，遇到‘1’岛屿的数量加一，同时将‘1’以及周围的‘1’清零，因为连续的‘1’算一个岛屿，这样清零就可以保证一个岛屿只被计算一次，这里采用的是深度优先遍历和沉岛思想。

### 代码

```c
void dfs_down(char** grid,int gridSize,int* gridColSize,int i,int j){
    if(i<0||j<0||i>=gridSize||j>=gridColSize[i]||grid[i][j]=='0') return ;
    grid[i][j] = '0';
    dfs_down(grid,gridSize,gridColSize,i-1,j);
    dfs_down(grid,gridSize,gridColSize,i+1,j);
    dfs_down(grid,gridSize,gridColSize,i,j-1);
    dfs_down(grid,gridSize,gridColSize,i,j+1);
}
int numIslands(char** grid, int gridSize, int* gridColSize){
    int res = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if(grid[i][j]=='1'){
                res++;
                dfs_down(grid,gridSize,gridColSize,i,j);
            }
        }
    }
    return res;
}
```