### 解题思路
* 方法三：动态规划-自下而上
* 没有采用官方的Arrays.fill(dp,amount+1),这样不容易理解
* dp[(long)i+ coins[j]中要把i金额转换为long型，避免coins-j给定一个很大整数造成越界。

### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        if(amount == 0) {
            return 0;
        }
        // dp[i]代表凑成金额i所需要的最小金币的个数，多一个为了剔除0
        int[] dp = new int[amount + 1];
        Arrays.fill(dp,Integer.MAX_VALUE);
        // 单个硬币金额直接等于amount则需要最小金币为1
        for (int i = 0; i < coins.length; i++) {
           if (coins[i] <= amount) {
                dp[coins[i]] = 1;
           }
        }
        for (int i = 1; i <= amount; i++) {
            if(dp[i] < Integer.MAX_VALUE) {
                // amount = i的金额可以凑出来
                for (int j = 0; j < coins.length; j++) {
                    if ((long)i + coins[j] <= amount) {
                        dp[i + coins[j]] = Math.min(dp[i] + 1,dp[(long)i+ coins[j]]);
                    }
                }
            }
        }
        if(dp[amount] == Integer.MAX_VALUE) {
            return -1;
        }
        return dp[amount];
    }
     
}
```