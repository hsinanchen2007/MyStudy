### 解题思路
**动态规划**
注意点：
两个方向：1. 向右 2. 向下
障碍物： 标识为1

状态位置 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
第i,j位置的路径条数，一定等于到达i-1,j的路径条数 + 到达i,j-1的路径条数。

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {

        int row = obstacleGrid.length;
        int col = obstacleGrid[0].length;
        int[][] dp = new int[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (obstacleGrid[i][j] == 1) continue;  //如果当前位置是障碍物，则不记录
                if (i == 0 && j == 0) dp[i][j] = 1;    // 特判! 如果是在左上角，则赋值1

                dp[i][j] += i > 0 ? dp[i - 1][j] : 0;  //状态转移： 从上方下来的（判断是否有上方，i > 0)
                dp[i][j] += j > 0 ? dp[i][j - 1] : 0;  //状态转移： 从左方过来的（判断是否有左方，j > 0)
            }
        }
        return dp[row - 1][col - 1];
    }
}
```

执行用时 :1 ms, 在所有 Java 提交中击败了90.92% 的用户
内存消耗 :38.6 MB, 在所有 Java 提交中击败了5.08%的用户