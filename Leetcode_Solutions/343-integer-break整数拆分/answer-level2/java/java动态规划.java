```
if (n == 2)
            return 1;
        else if (n == 3)
            return 2;
        int[] dp = new int[n + 1];
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i < dp.length; i++) {
            dp[i] = Math.max(dp[i - 2] * 2, dp[i - 3] * 3);
        }
        return dp[n];
```
看了前面几个题解，好像都没有我这思路，反正最后不是乘3就是乘2，如果不用数组，空间复杂度也可以是1
