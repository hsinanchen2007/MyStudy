### 代码

```java
class Solution {
    public int dieSimulator(int n, int[] rollMax) {
        int mod = 1000000007;
        int[][] dp = new int[n + 1][7];
        //dp[i][j] 代表当前序列长度为i个，以j结尾
        //dp[i][6] 代表以0-6结尾的长度为i的序列数量之和
        //dp[i][6] = dp[i][k] for k in 0 to 5
        dp[0][6] = 1;

        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j < 6; j ++) {
                dp[i][j] = dp[i - 1][6];
                if (i - rollMax[j] > 0) {
                    // 删除掉以rollMax[j] 个 j 结尾的序列
                    int reduce = dp[i - rollMax[j] - 1][6] - dp[i - rollMax[j] - 1][j];
                    dp[i][j] = ((dp[i][j] - reduce) % mod + mod) % mod;
                }
                dp[i][6] += dp[i][j];
                dp[i][6] %= mod;
            }
        }
        return dp[n][6];
    }
}
```