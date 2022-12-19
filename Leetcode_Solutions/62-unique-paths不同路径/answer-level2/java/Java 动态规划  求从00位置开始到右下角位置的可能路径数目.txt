### 解题思路
由题可知，要么向下要么向右，因此定一个dp二维数组存储每个节点作为终点的可能路径数目。
转移方程：dp[i][j] = dp[i -1][j] + dp[i][j - 1];
需要注意的是初始化，第一行和第一列的任意一个节点作为终点时，路径数目为1.

### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i -1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
}
```