### 解题思路
定义dp[i][j]为包含第i行第j列元素时的最小路径和

通用情况： dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + val[i][j]
基本情况： dp[0][0] = val[0][0]

对第一行的元素， 以及其它每一行最左侧的和最右侧的元素做特殊处理

### 代码

如果没有记忆化搜索， 会超时
```
var minimumTotal = function(triangle) {
  function dp (i, j) {
    if (i === 0) {
      return triangle[0][0]
    }
    if (i === j) {
      return dp(i - 1, j - 1) + triangle[i][j]
    }
    if (j === 0) {
      return dp(i - 1, 0) + triangle[i][j]
    }
    return Math.min(dp(i - 1, j), dp(i - 1, j - 1)) + triangle[i][j]
  }
  let res
  for (let k = 0; k < triangle[triangle.length - 1].length; ++k) {
    const _res = dp(triangle.length - 1, k)
    if (res === undefined) {
      res = _res
    } else {
      res = Math.min(res, _res)
    }
  }
  return res
};
```

加上记忆化搜索
```javascript
/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
  const memory = {}
  function dp (i, j) {
    if (memory[i] === undefined) {
      memory[i] = {}
    } else {
      if (memory[i][j] !== undefined) {
        return memory[i][j]
      }
    }
    if (i === 0) {
      return memory[i][j] = triangle[0][0]
    }
    if (i === j) {
      return memory[i][j] = dp(i - 1, j - 1) + triangle[i][j]
    }
    if (j === 0) {
      return memory[i][j] =  dp(i - 1, 0) + triangle[i][j]
    }
    return memory[i][j] =  Math.min(dp(i - 1, j), dp(i - 1, j - 1)) + triangle[i][j]
  }
  let res
  for (let k = 0; k < triangle[triangle.length - 1].length; ++k) {
    const _res = dp(triangle.length - 1, k)
    if (res === undefined) {
      res = _res
    } else {
      res = Math.min(res, _res)
    }
  }
  return res
};
```