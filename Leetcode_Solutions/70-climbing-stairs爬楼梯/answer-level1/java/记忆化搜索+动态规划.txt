### 解题思路
![屏幕快照 2020-01-22 16.25.01.png](https://pic.leetcode-cn.com/794ccab66b3938e944f80f3e86931fb81de410823b58cf20cca5b7f570f4717f-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-22%2016.25.01.png)


### 记忆化搜索

```java
class Solution {
    int[] memo;
    public int climbStairs(int n) {
        memo = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            memo[i] = -1;
        }
        if (n == 0) {
            return 1;
        }
        return calcWays(n);
    }

    private int calcWays(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (memo[n] == -1) {
            memo[n] = calcWays(n - 1) + calcWays(n - 2);
        }
        return memo[n];
    }
}
```

### 动态规划

```java
class Solution {
    public int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int[] memo = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            memo[i] = -1;
        }
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 2; i <= n; i++) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo[n];
    }
}
```