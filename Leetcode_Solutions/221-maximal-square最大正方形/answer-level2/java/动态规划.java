### 解题思路
动态转移方程为：
dp[i][j] = Math.min(Math.min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;

### 代码

```java
class Solution {
    public int maximalSquare(char[][] matrix) {
        //边届条件
        if (matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        //动态规划 木桶短板效应
        //dp[i][j] 表示以i,j为右下角的矩形最大边长
        //状态转移方程为 dp[i][j] = Math.min(Math.min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1
        
        //行
        int rows = matrix.length;
        //列
        int cols = matrix[0].length;

        //设置dp数组
        int[][]  dp = new int[rows+1][cols+1];

        //设置最大边长
        int max  = 0;
        
        //两次for循环
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    dp[i+1][j+1] = Math.min(Math.min(dp[i][j+1], dp[i+1][j]), dp[i][j]) + 1;
                    max = Math.max(dp[i+1][j+1], max);
                }
            }
        } 

        return max*max;
    }
}
```