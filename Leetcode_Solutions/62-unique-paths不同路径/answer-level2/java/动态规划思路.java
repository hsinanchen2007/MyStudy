### 解题思路
简单动态规划题
二维dp[i][j]数组 i,j 表示i行j列的数据有多少种走法
状态转移方程是: dp[i][j] = dp[i][j-1] + dp[i-1][j]
dp初始条件 第一行 第一列都只有一种走法 初始化即可
最后返回dp[m-1][n-1]即可

### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        //动态规划思路
        int[][] dp = new int[m][n];
        
        //初始化dp状态数组
        for (int i = 0; i < n; i++) {//第1行 只有一个状态
            dp[0][i] = 1;
        }

        for (int i = 0; i < m; i++) {//第1列 只有一个状态
            dp[i][0] = 1;
        }

        //对二维数组进行求dp状态
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                //状态转移方程
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }

        return dp[m-1][n-1];
    }
}
```