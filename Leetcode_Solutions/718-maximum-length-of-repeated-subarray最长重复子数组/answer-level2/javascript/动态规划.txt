### 解题思路

大家好，我是 17

动态规划最重要的就是递推方程，本题的递推方程是 如果第一个字符串的第`i+1`个字符，和第二个字符串的第`j+1`个字符相等，那么第`i+1`到第`j+1`的最长公共子串长度 `dp[i+1][j+]=dp[i][j]+1`


### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number}
 */
var findLength = function (A, B) {
  let max = 0
  let dp = Array.from({ length: A.length + 1 }, () => new Array(B.length + 1).fill(0))

  for (let i = 0; i < A.length; i++) {
    for (let j = 0; j < B.length; j++) {
      if (A[i] === B[j]) {
        dp[i + 1][j + 1] =dp[i][j]+1
        max = Math.max(dp[i + 1][j + 1], max)
      }
    }
  }
  return max
};
```