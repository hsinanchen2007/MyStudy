机器人可以往下往右走一格，转移方程Grid[i][j] = Grid[i-1][j]+Grid[i][j-1];
如果有障碍物，当前点的路径数化为零
```
class Solution {
    public int uniquePathsWithObstacles(int[][] Grid) {
        int n = Grid.length,m = Grid[0].length; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
            if(Grid[i][j] == 1) Grid[i][j] = 0;//障碍物直接返回0
            else if(i == 0 && j == 0) Grid[i][j] = 1;//起点
            else if(i == 0 ) Grid[i][j] = Grid[i][j-1];//只能从左边走 第一行 是同一条路
            else if(j == 0 ) Grid[i][j] = Grid[i-1][j];//同第一行
            else 
                Grid[i][j] = Grid[i-1][j]+Grid[i][j-1];
            //可以往下往右，当前点的路径数等于 Grid[i-1][j]+Grid[i][j-1]之和
            }
        }
        return Grid[n-1][m-1];
    }
}
```
