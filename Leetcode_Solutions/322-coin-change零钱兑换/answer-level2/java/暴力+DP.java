面试栽过
### 状态定义
dp[n]: 表示使用给定的coins加到n所需要的最少个数
### 状态转移
`dp[n] = min{dp[c]} + 1` 
c满足: **coin + c = n, coin为coins中的一个硬币**
# 代码
```
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (coins == null) return -1;
        long[] dp = new long[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int i = 1; i < dp.length; ++i) {
            for (int j : coins) {
                if (i - j >= 0 && dp[i-j] != -1) {
                    dp[i] = Math.min(dp[i], dp[i-j] + 1);
                }
            }
        }
        return dp[amount] == Integer.MAX_VALUE ? -1 : (int)dp[amount];
    }
}
```
时间复杂度: O(k·n), n为amout, k为coins个数
空间复杂度: O(n), n为amount



