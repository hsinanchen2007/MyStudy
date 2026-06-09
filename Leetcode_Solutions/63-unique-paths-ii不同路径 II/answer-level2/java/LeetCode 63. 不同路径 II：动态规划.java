### 解题思路
这个题是典型的坐标型动态规划，或者叫做计数型动态规划
跟 不同路径 唯一不同的是可能有些格子不能走，其实大致思路是不变的，只是需要在初始值方面做些改动
解题步骤：
    1. 初始化，找出子问题
    2. 列出状态转移方程
    3. 列出边界问题
子问题其实就是找处到达result[m-1][n]的路径数+result[m][n-1]的路径数
所以状态转移方程：result[i][j]=result[i-1][j]+result[i][j-1]
初始化：result[0][0]=1;
当obstacleGrid[i][j]=1时，result[i][j]=0;
其余情况都置为0；
因为这时候，边界i=0和j=0并不能直接赋值为1,所以就分别计算
最后返回result[m-1][n-1]即可

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m=obstacleGrid.length;
        int n=obstacleGrid[0].length;
        int[][] result=new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    result[i][j]=0;
                    continue;
                }
                if(i==0&&j==0){
                    result[i][j]=1;
                    continue;
                }
                result[i][j]=0;
                if(i>0){
                    result[i][j]+=result[i-1][j];
                }
                if(j>0){
                    result[i][j]+=result[i][j-1];
                }
            }
        }
        return result[m-1][n-1];
    }
}
```