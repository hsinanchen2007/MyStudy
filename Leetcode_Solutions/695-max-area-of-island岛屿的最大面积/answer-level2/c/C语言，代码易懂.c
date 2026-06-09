### 解题思路
我声明了一个辅助二维数组来记录哪些已经被访问了。
这道题的逻辑并不困难，相信大家看代码就能看懂。不多描述
其实也可以不用辅助数组解题，直接把原数组中遍历过的元素修改为0，一边遍历一边统计。
![图片.png](https://pic.leetcode-cn.com/4be95b76062ca72a5146397daef26590f92f323b05e1cdf06bad1a163ada3bc0-%E5%9B%BE%E7%89%87.png)

### 代码

```c
int cacularea(int**grid,int **gridvisited,int i,int j,int gridSize, int* gridColSize){
    int sum=1;
    gridvisited[i][j]=1;
    if(i+1<gridSize&&j<gridColSize[i+1]&&grid[i+1][j]==1&&gridvisited[i+1][j]!=1){
        sum+=cacularea(grid,gridvisited,i+1,j,gridSize,gridColSize);
    }
    if(j+1<gridColSize[i]&&grid[i][j+1]==1&&gridvisited[i][j+1]!=1){
        sum+=cacularea(grid,gridvisited,i,j+1,gridSize,gridColSize);
    }
    if(i-1>=0&&grid[i-1][j]==1&&gridvisited[i-1][j]!=1){
        sum+=cacularea(grid,gridvisited,i-1,j,gridSize,gridColSize);
    }
    if(j-1>=0&&grid[i][j-1]==1&&gridvisited[i][j-1]!=1){
        sum+=cacularea(grid,gridvisited,i,j-1,gridSize,gridColSize);
    }
    return sum;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int **gridvisited=(int **)malloc(sizeof(int*)*gridSize);
    for(int i=0;i<gridSize;i++){//一个标志数组
        gridvisited[i]=(int*)calloc(gridColSize[i],sizeof(int));
    }
    int maxarea=0;int area=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if(grid[i][j]!=0&&gridvisited[i][j]!=1){
                area=cacularea(grid,gridvisited,i,j,gridSize,gridColSize);
                if(area>maxarea){
                    maxarea=area;
                }
            }else{
                gridvisited[i][j]=1;
            }
        }
    }
    return maxarea;
}
```