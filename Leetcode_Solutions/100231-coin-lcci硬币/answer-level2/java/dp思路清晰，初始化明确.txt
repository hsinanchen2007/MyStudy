### 解题思路
动态规划，思路清晰。初始化明确

### 代码

```java
class Solution {
    public int waysToChange(int n) {

        if (n < 5)
            return 1;
        if (n == 5)
            return 2;
        int[] coins = {1, 5, 10, 25};
        int[][] dp = new int[4][n + 1];
        // 当数量为0，1时，有1种表示法
        for(int i = 0; i < 4; ++i){
             dp[i][0] = 1;
             dp[i][1] = 1;
        }  
        // 当只有一种硬币时，只有1种表示法
        for(int i = 0; i <=n; ++i)
            dp[0][i] = 1;
        /*
         * 状态：dp[i][j]表示[0...i]种硬币能组合为j的所有不同种数
         * 状态转移：取 或 不取 当前硬币coins[i]
         */
        for (int i = 1; i < 4; ++i) {
            for (int j = 2; j <= n; ++j) {
                if (j >= coins[i])
                    dp[i][j] = (dp[i][j - coins[i]] + dp[i - 1][j]) % 1000000007;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[3][n];
    }
}
```