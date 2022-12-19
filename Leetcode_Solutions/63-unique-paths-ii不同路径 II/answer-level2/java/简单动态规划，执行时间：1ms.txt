### 解题思路
计算每格的路径数，初始化第一行和第一列为1，遇到障碍设置为0，且在之后的格子初始化为0；
其他格子遇到障碍设置为0，未遇到障碍时，转移方程为：obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];

### 代码

```java
class Solution {
     public int uniquePathsWithObstacles(int[][] obstacleGrid) { // m是行，n是列
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        boolean flag = false;
        if(obstacleGrid[0][0] == 1) return 0;
         for (int i = 0; i < n; i++) {
            if(obstacleGrid[0][i] == 1 || flag == true) {
                obstacleGrid[0][i] = 0;
                flag = true;
            } else {
                obstacleGrid[0][i] = 1;
            }
        }
        flag = false;
        for (int i = 1; i < m; i++) {
            if(obstacleGrid[i][0] == 1 || flag == true) {
                obstacleGrid[i][0] = 0;
                flag = true;
            }
            else obstacleGrid[i][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
}
```