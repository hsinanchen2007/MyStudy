![image.png](https://pic.leetcode-cn.com/cadf6693dcc6d816cd2a772c11636c3204408b501a7755414d3b48c8cb6eeaad-image.png)

### 解题思路
```javascript
动态规划：
分析状态转移方程：
- 对于每一个格子：
  走到它的路径数 = 到达它上面格子的路径数 + 到达它左面格子的路径数
  dp[i] = dp[i - 1][j] + dp[j - 1][i]
最后求 dp[m - 1][n - 1]
```

### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */

var uniquePaths = function(m, n) {
  if (m === 0 || n === 0) return 0;
  if (m === 1 || n === 1) return 1;
  
  let dp = [];
  for (let i = 0; i < m; i++) { dp.push( [] ) };
  dp[0][0] = 1;
  
  // 遍历每一个格子，如果越界，那就为0
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (i === 0 && j === 0) continue;
      let top = i === 0 ? 0 : dp[i - 1][j],
          left = j === 0 ? 0 : dp[i][j - 1];
      dp[i][j] = top + left;
    }
  }
  
  return dp[m - 2][n - 1] + dp[m - 1][n - 2];
};





```