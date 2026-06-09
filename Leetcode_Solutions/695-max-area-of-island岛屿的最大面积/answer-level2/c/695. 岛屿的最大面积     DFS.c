### 解题思路
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

 

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。




奇怪此题将 grid[i][j] = 0; 
放到递归入口处就没问题，
放到下面各判断里面就不对了，感觉乱序执行导致的异常

### 代码

```c


int dfs(int **grid, int i, int j,int gridSize, int* gridColSize){
    int sum = 1;
    grid[i][j] = 0;
    if(i-1 >= 0 && grid[i-1][j] == 1){
        //grid[i-1][j] = 0;
        sum += dfs(grid,i-1,j,gridSize,gridColSize);
    }

    if(i+1 < gridSize && grid[i+1][j] == 1){
       // grid[i+1][j] = 0;
        sum += dfs(grid,i+1,j,gridSize,gridColSize);
    }

    if(j-1 >= 0 && grid[i][j-1] == 1){
       // grid[i][j-1] = 0;
        sum += dfs(grid,i,j-1,gridSize,gridColSize);
    }
    
    if(j+1 < gridColSize[0] && grid[i][j+1] == 1){
       // grid[i][j+1] = 0;
        sum += dfs(grid,i,j+1,gridSize,gridColSize);
    }
    return sum;
}



int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int i, j;
    int max = 0,sum=0;
    //int res[50][50] = {0};
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[0];j++){
            if(grid[i][j] == 1){
                grid[i][j] == 0;
                
                sum = dfs(grid,i,j,gridSize,gridColSize);
                if(max < sum)  max =sum;
                sum = 0;
            }
        }
    }

    return max;
}
```