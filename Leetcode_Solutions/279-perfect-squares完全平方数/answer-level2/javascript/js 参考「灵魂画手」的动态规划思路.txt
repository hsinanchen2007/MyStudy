![image.png](https://pic.leetcode-cn.com/a889c0aa9d25bd810914393918ec5000753eebc3fa70d7d532495280d7f05a41-image.png)

### 解题思路
```js
  参考「灵魂画手」的动态规划思路，太巧妙了
```

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */

var numSquares = function(n) {
  let dp = new Array(n + 1);
  dp[0] = 0;
  
  for (let i = 1; i <= n; i++) {
    dp[i] = i;
    for (let j = 1; j * j <= i; j++) {
      dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
    }
  }
  
  return dp[n];
};
```