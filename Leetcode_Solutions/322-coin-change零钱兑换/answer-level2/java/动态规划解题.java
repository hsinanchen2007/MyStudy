1、回忆原始的走楼梯问题
11阶楼梯，从1楼走上去，每次最多上1或者2个台阶，一共有多少种走法？
F(n)表示走到n阶台阶的走法数目；
按照动态规划的逻辑，F(11) = F(10) + F(9);
依次类推：F(n) = F(n-1) + F(n-1);
边界为n=1或1；

2、硬币转化为走楼梯问题
11阶楼梯，我从1楼走上，每次最多可以上[1、2、5]个台阶，一共有多少种走法（步数最小的走法）？
按照动态规划的逻辑
F(n)表示走到n阶台阶的最小步数：
F(11) = min(F(11-1), F(11-2), F(11-5)) + 1;
边界为n = 0；

```
public int coinChange(int[] coins, int amount) {
        if (coins.length == 0 )
            return -1;
        
        if (amount == 0)
            return 0;
        
        int[] dp = new int[amount + 1];
        
        //题目求最小值，初始值都设置为最大的amount+1
        for (int l = 0; l < dp.length; l++) {
            dp[l] = amount + 1;
        }
        
        dp[0] = 0;
        
        for (int i = 0; i <= amount; i++) {
            
            for (int j = 0; j < coins.length; j++) {
                
                //如果硬币面额大于总金额，说明无法凑齐，就continue；
                
                //如果当前硬币面额coins[j]小于等于当前的总金额i；
                if (coins[j] <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        
        return dp[amount] == (amount + 1) ? -1 : dp[amount];        
        
    }
```
