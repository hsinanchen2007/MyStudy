
### 解题思路
原本我看这道简单题，就用了最简单粗暴的思路去遍历，但好像效率还挺不错的……那就不去尝试别的算法了
单纯就是遍历找2，修改四周的1。用flag标记是否需要继续腐烂，用-1赋值该躺腐烂橘子，避免在同一趟遍历中再次被发现。

### 代码

```c
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int i,j,flag=1,tmp=0;
    while(flag==1)
    {
        flag=0;
        for(i=0;i<gridSize;i++){
            for(j=0;j<*gridColSize;j++){
                if(grid[i][j]==2){
                    if(i+1<gridSize&&grid[i+1][j]==1){
                        grid[i+1][j]=-1;
                        flag=1;
                    }
                    if(j+1<*gridColSize&&grid[i][j+1]==1){
                        grid[i][j+1]=-1;
                        flag=1;
                    }
                    if(i-1>=0&&grid[i-1][j]==1){
                        grid[i-1][j]=-1;
                        flag=1;
                    }
                    if(j-1>=0&&grid[i][j-1]==1){
                        grid[i][j-1]=-1;
                        flag=1;
                    }
                }
            }
        }
        for(i=0;i<gridSize;i++){
            for(j=0;j<*gridColSize;j++){
                if(grid[i][j]==-1) grid[i][j]=2;
            }
        }
        if(flag==1) tmp++;
    }
    for(i=0;i<gridSize;i++){
        for(j=0;j<*gridColSize;j++){
            if(grid[i][j]==1) return -1;
        }
    }
    return tmp;
}
```