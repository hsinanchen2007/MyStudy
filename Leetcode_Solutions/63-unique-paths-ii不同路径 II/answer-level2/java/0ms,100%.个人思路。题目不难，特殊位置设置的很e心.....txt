![image.png](https://pic.leetcode-cn.com/ab101194fe607a8a5955f3688c0e08b42239f89e5826fe243f763a5282fd907c-image.png)

分析：
对于位置 dp[i][j]处的路径条数，是由位置dp[i][j-1]和dp[i-1][j]的和决定的。
位置可以分为有无障碍。
有障碍，到达该位置的路径条数直接设置为0.
无障碍，左上相加。
特殊情况考虑，第一行第一列是否有障碍，同时进行初始化。
有障碍，障碍处及障碍后全部变0.即停止遍历。

```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        //考虑特殊情况
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        if(obstacleGrid[0][0] == 0 && m == 1 && n== 1)return 1;
        //定义二维数组
        int [][] dp = new int [m][n];
        //第一行边界位置初始化
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] != 1){
                dp[i][0] = 1;
            }else{
                break;
            }
        }
        //第一列边界位置初始化
        for(int j = 0; j < n; j++){
            if(obstacleGrid[0][j] != 1){
                dp[0][j] = 1;
            }else{
                break;
            }
        }
        //遍历赋值
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] != 1){
                   dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }

        return dp[m-1][n-1];
    }
}
```
