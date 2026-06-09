# 递归+存储
```
class Solution {
    public int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int[] dp = new int[n];
        dp[0] = 1;
        dp[1] = 2;
        return helper(n - 1, dp);
    }
    private int helper(int n, int[] dp) {
        if (dp[n] == 0) {
            dp[n] = helper(n - 1) + helper(n - 2);
            return dp[n];
        } else {
            return dp[n];
        }
    }
}
```
时间复杂度: O(n)
空间复杂度: O(n)
# 动态规划
```
class Solution {
    public int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int[] dp = new int[n];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
}
```
时间复杂度: O(n)
空间复杂度: O(n)
**进一步减少不必要的空间存储，n只需要用到n-1、n-2两个解即可**
```
class Solution {
    public int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int result = 0;
        int first = 1;
        int second = 2;
        for (int i = 2; i < n; ++i) {
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
}
```
时间复杂度: O(n)
空间复杂度: O(1)