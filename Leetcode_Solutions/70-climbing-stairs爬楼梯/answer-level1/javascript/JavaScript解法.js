### 解题思路
动态规划，n阶台阶可以分成，从dp[n-1]处+1个台阶或者dp[n-2]处+2个台阶，这样可以往下递推dp[n-1]和dp[n-2]的走法，所以总共是dp[n-1] + dp[n -2]，至于为什么要穷取n = 1和2是因为 dp[-1]和dp[0]都是没有意义的。要把边界条件给排除

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if (n === 0 || n === 1 || n === 2) return n;
    const dp = [];
    // dp[n] = dp[n - 1] + dp[n - 2]
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (let i = 3; i <= n; i ++) {
        dp[i] = dp[i - 1] + dp[i - 2]
    }
    return dp[n]
};
```