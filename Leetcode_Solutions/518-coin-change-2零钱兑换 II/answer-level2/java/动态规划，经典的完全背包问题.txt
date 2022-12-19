经典的完全背包问题，关于01背包与完全背包可以参考此处。
[背包问题详解](https://blog.csdn.net/reed1991/article/details/53352426)

参考代码如下
```
public int change(int amount, int[] coins) {
        if (coins == null) {
            return 0;
        }
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];

    }
```
