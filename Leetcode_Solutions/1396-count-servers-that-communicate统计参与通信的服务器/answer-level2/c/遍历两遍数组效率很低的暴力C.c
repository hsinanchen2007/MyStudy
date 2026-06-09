### 解题思路
用两个数组记录各行各列服务器存在情况，遍历两遍数组，如果该位置存在服务器且与之同行or同列服务器个数大于1则将该位置标记为1

### 代码

```c
int countServers(int** grid, int gridSize, int* gridColSize){
    int m=gridSize;
    int n=*gridColSize;
    int count_m[m],count_n[n];
    for(int i=0;i<m;i++){
        count_m[i]=0;
    }
    for(int i=0;i<n;i++){
        count_n[i]=0;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                count_m[i]++;
                count_n[j]++;
            }
        }
    }
    int result=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1&&(count_m[i]>1||count_n[j]>1)){
                result++;
            }
        }
    }
    return result;
}
```