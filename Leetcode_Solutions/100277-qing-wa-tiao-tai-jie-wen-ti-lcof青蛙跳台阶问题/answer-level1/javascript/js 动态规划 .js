![image.png](https://pic.leetcode-cn.com/c1d660f881644247e7aae2374aa40aa09b4723cfd38036c3954f6d230e3ec47b-image.png)

### 解题思路
```javascript
动态规划：

分析：
跳到第 5 个台阶的方法：
1.从 4 跳过来
2.从 3 跳过来
3.所以 dp[5] = dp[5 - 1] + dp[5 - 2]

状态转移方程:
dp[n] = dp[n - 1] + dp[n - 2]
```

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */

var numWays = function(n) {
  let dp = [];
  dp[0] = 1;
  dp[1] = 1;
  for (let i = 2; i <= n; i++) {
    let c = dp[i - 1] + dp[i - 2];
    dp[i] = c > 1000000007 ? c % 1000000007 : c;
  }
  
  return dp[n];
};
```