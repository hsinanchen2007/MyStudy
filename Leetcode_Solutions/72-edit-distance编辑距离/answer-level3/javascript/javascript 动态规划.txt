### 解题思路


### 代码

```javascript
/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    const n = word1.length
    const m = word2.length
    // 如果有一个字符串为空
    if (!n || !m) {
        return n + m
    }
    // DP 数组
    const dp = new Array()
    for (let i = 0; i < n + 1; i ++) {
        dp.push([])
    }
    // 边界状态初始化
    for (let i = 0; i < n + 1; i++) {
      dp[i][0] = i;
    }
    for (let j = 0; j < m + 1; j++) {
      dp[0][j] = j;
    }
    // 计算所有 DP 值
    for (let i = 1; i < n + 1; i++) {
      for (let j = 1; j < m + 1; j++) {
        let left = dp[i - 1][j] + 1;
        let down = dp[i][j - 1] + 1;
        let left_down = dp[i - 1][j - 1];
        if (word1.charAt(i - 1) !== word2.charAt(j - 1))
          left_down += 1;
        dp[i][j] = Math.min(left, down, left_down);
      }
    }
    return dp[n][m];
};
```