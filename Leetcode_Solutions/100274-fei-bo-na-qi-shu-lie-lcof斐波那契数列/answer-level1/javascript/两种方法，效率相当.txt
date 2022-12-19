### 解题思路
经典的问题，mark一下解法

### 代码
递归 + 哈希表
```javascript
/**
 * @param {number} n
 * @return {number}
 */
// base case: f(1) = f(2)= 0
// 状态转移方程： f(n) = f(n - 1) + f(n - 2)
// dp table优化

// 用递归思想+memo表，自顶向下解
var helper = function (map, n) {
    if (n === 1 || n === 2) return 1
    if (map[n]) return map[n]
    map[n] = (helper(map, n-1) + helper(map, n-2)) % 1000000007
    return map[n]
}

var fib = function(n) {
    if (n < 1) return 0
    // 通过哈希表缓存，空间换时间。复杂度从2^n降低到了n
    const map = {}
    return helper(map, n)
};
```

迭代
```
// 另一种思路，直接通过累加这张dp表，迭代求解
var fib = function (n) {
    const dp = [0, 1, 1]
    for (let i = 3; i <= n; i ++) {
        dp[i] = (dp[i - 1] + dp[i -2]) % 1000000007
    }
    return dp[n]
}

```