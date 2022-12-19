## 手稿
### [LeetCode笔记-Java版](http://note.youdao.com/noteshare?id=383f28fda2c91ea9736e71a189c80718&sub=09A29EF846D4455EA2C67845DD054759)
### [LeetCode笔记-Java版-专题篇](https://note.youdao.com/ynoteshare1/index.html?id=e3152a4cf9f16867c36adce45bc134cb&type=note)

## 322. 零钱兑换 LeetCode Medium 完全背包
## 方法1：DP 基础版
- 执行用时 :53 ms, 在所有 Java 提交中击败了10.69%的用户
- 内存消耗 :47.3 MB, 在所有 Java 提交中击败了5.95%的用户
 
```
 public int coinChange(int[] coins, int amount) {
        int[][] dp = new int[coins.length][amount + 1];
        for (int j = 1; j <= amount; j++) {
            dp[0][j] = Integer.MAX_VALUE;
            if (j - coins[0] >= 0 && dp[0][j - coins[0]] != Integer.MAX_VALUE) {
                dp[0][j] = dp[0][j - coins[0]] + 1;
            }
        }
        for (int i = 1; i < coins.length; i++) {
            for (int j = 1; j <= amount; j++) {
                int temp = Integer.MAX_VALUE;
                if (j - coins[i] >= 0 && dp[i][j - coins[i]] != Integer.MAX_VALUE) {
                    temp = dp[i][j - coins[i]] + 1;
                }
                dp[i][j] = Math.min(dp[i - 1][j], temp);
            }
        }
        return dp[coins.length - 1][amount] == Integer.MAX_VALUE ? -1 : dp[coins.length - 1][amount];
    }
```


## 方法2：DP 空间压缩 O(1)
- 执行用时 :17 ms, 在所有 Java 提交中击败了92.84%的用户
- 内存消耗 :35.9 MB, 在所有 Java 提交中击败了94.99%的用户

```
public int coinChange2nd(int[] coins, int amount) {
    int[] dp = new int[amount + 1];
    for (int j = 1; j <= amount; j++) {
        dp[j] = Integer.MAX_VALUE;
        if (j - coins[0] >= 0 && dp[j - coins[0]] != Integer.MAX_VALUE) {
            dp[j] = dp[j - coins[0]] + 1;
        }
    }

    for (int i = 1; i < coins.length; i++) {
        for (int j = 1; j <= amount; j++) {
            int temp = Integer.MAX_VALUE;
            if (j - coins[i] >= 0 && dp[j - coins[i]] != Integer.MAX_VALUE) {
                temp = dp[j - coins[i]] + 1;
            }
            dp[j] = Math.min(temp, dp[j]);

        }
    }
    return dp[amount] != Integer.MAX_VALUE ? dp[amount] : -1;
}
```


