![image.png](https://pic.leetcode-cn.com/34d32c1016fd96eff7f789c7a3b7f77ca2a4a6a4243cd3a350d897156fcc4904-image.png)
```
void dfs(char** grid,int i,int j,int high,int lenth) {
    grid[i][j] = '0';
    int h[] = {1,-1,0};
    int p[] = {1,-1,0};
    for (int k = 0;k<3;k++) {
        for (int u = 0;u<3;u++) {
            if (k!=u) {
                if ((k==0&&u==1)||(k==1&&u==0)) {
                    continue;
                } else {
                    if (i+h[k]<high && i+h[k]>=0 && j+p[u]<lenth && j+p[u] >= 0 && grid[i+h[k]][j+p[u]]=='1') {
                    dfs(grid,i+h[k],j+p[u],high,lenth);
                }
                }
            }
        }
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize){
    int lenth = gridColSize[0],high = gridSize;
    if (!grid) {
        return 0;
    }
    int count = 0;
    for (int i = 0;i<high;i++) {
        for (int j = 0;j<lenth;j++) {
            if (grid[i][j]=='1') {
                count++;
                dfs(grid,i,j,high,lenth);
            }
        }
    }
    return count;
}
```

