
经典的完全背包问题，关于01背包与完全背包可以参考此处。
[背包问题详解](https://blog.csdn.net/reed1991/article/details/53352426)
```
public int coinChange(int[] coins, int amount) {
        if (coins == null || coins.length == 0 || amount == 0) {
            return 0;
        }
        int[] dp = new int[amount + 1];
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                //如果需要组成的金额正好和某个硬币的面额相等
                if (coin == i) {
                    dp[i] = 1;
                } else {
                    //只有能凑成dp[i - coin]才能凑成dp[i]
                    if (dp[i - coin] != 0) {
                        if (dp[i] == 0) {
                            //暂时能凑成dp[i-coin]，但是凑不成dp[i]，那么直接将dp[i-coin]+1
                            dp[i] = dp[i - coin] + 1;
                        } else {
                            //既能凑成dp[i-coin]，又能凑不成dp[i]，那么取dp[i-coin]+1和dp[i]的较小值
                            dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                        }

                    }

                }
            }
        }
        return dp[amount] == 0 ? -1 : dp[amount];

    }
```
