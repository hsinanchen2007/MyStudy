### 解题思路

找到状态转移方程  dp[i] = dp[i-Math.pow(2, n)] + 1

其中 n 表示不超过 i 的最大2的幂次数

e.g.  
```
  dp[9] = dp[9-8] + 1
  dp[8] = dp[8-8] + 1
  dp[7] = dp[7-4] + 1
```

### 代码

```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
  if (num === 0) return [0]
  let dp = [0]
  let n = 0
  for (let i = 1; i <= num; i++) {
    if (Math.pow(2, n+1) <= i) {
      n++
    }
    dp[i] = dp[i-Math.pow(2, n)] + 1
  }
  return dp
};
```