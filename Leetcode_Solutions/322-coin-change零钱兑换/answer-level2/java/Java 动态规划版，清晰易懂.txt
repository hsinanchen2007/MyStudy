### 解题思路
class Solution {
    经典的动态规划解题思路    
 f(n) = min(f(n-c1),f(n-c2),f(n-c3),...f(n-cn))+1。
     f(n) 表示要凑齐金额为 n 的最小硬币数量。
     两个例子去验证：[1,3,5] amount = 9
     [2] amount = 3
### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
         if(amount == 0) return 0;
         int[] dp = new int[amount +1];
        // 第一个钱包表示价值为 0，其他钱包价值初始化为无穷大。
         Arrays.fill(dp,1,dp.length,Integer.MAX_VALUE);
         for(int i = 1; i < dp.length; i++) {
             // 填充 dp 数组
             for(int coin: coins) {
                 if(i- coin >= 0 && dp[i-coin] != Integer.MAX_VALUE) {
                     dp[i] = Math.min(dp[i],dp[i-coin] +1);
                 }
             }
         }
         return (dp[amount] == Integer.MAX_VALUE) ? -1:dp[amount];

    }
}
```