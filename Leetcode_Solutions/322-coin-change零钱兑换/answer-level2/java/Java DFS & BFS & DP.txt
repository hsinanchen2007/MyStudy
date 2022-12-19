1、DFS
```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount < 1) return 0;
        return coinChangeHelper(coins, amount, new HashMap<>());
    }

    int coinChangeHelper(int[] coins, int amount, Map<Integer, Integer> memo) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (memo.containsKey(amount)) return memo.get(amount);

        int count = -1;
        for (int coin : coins) {
            int remCount = coinChangeHelper(coins, amount - coin, memo);
            if (remCount == -1) continue;
            count = (count == -1) ? (remCount + 1) : Math.min(count, remCount + 1);
        }
        memo.put(amount, count);
        return count;
    }
}
```

2、BFS
```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount < 1) return 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(amount);
        HashSet<Integer> visited = new HashSet<>();
        int count = 0;
        while (!queue.isEmpty()) {

            int size = queue.size();
            while (--size >= 0) {
                int rem = queue.poll();
                if (rem == 0) return count;

                for (int coin : coins) {
                    if (coin > rem || visited.contains(rem - coin)) continue;
                    visited.add(rem - coin);
                    queue.offer(rem - coin);
                }
            }
            count++;
        }
        return -1;
    }
}
```

3、DP
```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount < 1) return 0;
        int[] dp = new int[amount + 1];
        for (int i = 1; i <= amount; i++) {
            int min = -1;
            for (int coin : coins) {
                if (coin > i || dp[i - coin] == -1) continue;
                min = (min == -1) ? (dp[i - coin] + 1) : Math.min(min, dp[i - coin] + 1);
            }
            dp[i] = min;
        }
        return dp[amount];
    }
}
```
稍作优化
```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount < 1) return 0;
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin > i) continue;
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
}
```


