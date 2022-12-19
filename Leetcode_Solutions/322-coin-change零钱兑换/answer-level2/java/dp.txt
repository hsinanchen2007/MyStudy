### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
    if(coins.length == 0)
            return -1;
        //声明一个amount+1长度的数组dp，代表各个价值的钱包，第0个钱包可以容纳的总价值为0，其它全部初始化为无穷大
        //dp[j]代表当钱包的总价值为j时，所需要的最少硬币的个数
        int[] dp = new int[amount+1];
        Arrays.fill(dp,1,dp.length,Integer.MAX_VALUE);
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                if(dp[j-coin] != Integer.MAX_VALUE) {
                    dp[j] = Math.min(dp[j], dp[j-coin]+1);
                }
            }
        }
        if(dp[amount] != Integer.MAX_VALUE)
            return dp[amount];
        return -1;
    }
}
```