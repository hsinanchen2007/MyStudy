### 解题思路
子问题：到点（i,j）一共有多少种可能，注意避开障碍物；
状态方程：p(i,j)表示到当前节点所有可能性，障碍物处理为p(i,j) = 0;
状态转移方程：p(i,j) = p(i-1,j) + p(i,j-1);
### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        
        if (obstacleGrid == null || obstacleGrid.length == 0) {
            return 0;
        }
        int[][] p = new int[obstacleGrid.length][obstacleGrid[0].length];
        for (int i=0;i<obstacleGrid.length;i++) {
            for (int j=0;j<obstacleGrid[0].length;j++) {
                if (i == 0 && j == 0 && obstacleGrid[i][j] == 0) {
                    p[i][j] = 1;
                    continue;
                }
                // 第一种障碍，设置为0
                if (obstacleGrid[i][j] == 1) {
                    p[i][j] = 0;
                    continue;
                } 
                // 靠边则设置为一种情况
                if (i == 0 && j > 0) { 
                    if (p[0][0] == 1) {
                        p[i][j] = p[i][j-1];
                    } else {
                        p[i][j] = 0;
                    }
                    continue;
                }
                if (j == 0 && i > 0) {
                    if (p[0][0] == 1) {
                        p[i][j] = p[i-1][j];
                    } else {
                        p[i][j] = 0;
                    }
                    continue; 
                }
                // 其他情况则设置为状态转移方程
                p[i][j] = p[i-1][j] + p[i][j-1];
            }
        }
        return p[obstacleGrid.length-1][obstacleGrid[0].length-1];
    }
}
```