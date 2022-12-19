>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：记忆化搜索

时间复杂度是O(coins.length * amount)。空间复杂度是O(amount)。

执行用时：205ms，击败5.05%。消耗内存：42.7MB，击败5.01%。

```java
public class Solution {
    private Map<Integer, Long> memo = new HashMap<>();

    public int coinChange(int[] coins, int amount) {
        long result = dfs(coins, amount);
        if (result == Integer.MAX_VALUE) {
            return -1;
        }
        return (int) result;
    }

    private long dfs(int[] coins, int amount) {
        if (memo.containsKey(amount)) {
            return memo.get(amount);
        }
        if (amount == 0) {
            memo.put(0, 0L);
            return 0;
        }
        long result = Integer.MAX_VALUE;
        for (int coin : coins) {
            if (coin <= amount) {
                result = Math.min(result, 1 + dfs(coins, amount - coin));
            }
        }
        memo.put(amount, result);
        return result;
    }
}
```

# 解法二：动态规划

状态定义：dp[i]：组成和为i的最少硬币的数量，当无法组成和为i时dp[i] = Integer.MAX_VALUE

状态转移：dp[i] = Math.min(dp[i], 1 + dp[i - coin])，其中coin为coins数组中的硬币值，满足coin <= i。

时间复杂度是O(coins.length * amount)。空间复杂度是O(amount)。

执行用时：18ms，击败38.55%。消耗内存：41.2MB，击败5.01%。

```java
public class Solution {
    public int coinChange(int[] coins, int amount) {
        long[] dp = new long[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0L;
        for (int i = 0; i < dp.length; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = Math.min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        return dp[amount] == Integer.MAX_VALUE ? -1 : (int) dp[amount];
    }
}
```