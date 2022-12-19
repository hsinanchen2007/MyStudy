直接暴力递归的时间复杂度是指数级别的，因为存在大量的重复计算。因此我们的优化思路就是，如何减少这些重复计算。

### 记忆化搜索
记忆化搜索是最直观的优化方案，通过将已经算过了的f(n)给缓存起来，从而达到将复杂度从指数优化到线性的目的。
```java
class Solution {
    public int tribonacci(int n) {
        int[] memory = new int[n + 1];
        return dfs(memory, n);
    }

    private int dfs(int[] memory, int n) {
        if(n <= 0) {
            return 0;
        }
        if(n == 1 || n == 2) {
            return 1;
        }
        if(memory[n] != 0) {
            return memory[n];
        }
        int sum = dfs(memory ,n - 3) + dfs(memory, n - 2) + dfs(memory, n - 1);
        memory[n] = sum;

        return sum;
    }
}
```

### 递推
记忆化搜索固然是简单的，但是缺陷是浪费空间。我们其实可以发现，对于n这个状态，只和n-1, n-2, n-3三个状态有关，因此其实这里空间可以优化成O(1)。
```java
class Solution {
    public int tribonacci(int n) {
        int[] dp = new int[4];
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            dp[i % 4] = dp[(i - 1) % 4] + dp[(i - 2) % 4] + dp[(i - 3) % 4];
        }

        return dp[n % 4];
    }
}
```