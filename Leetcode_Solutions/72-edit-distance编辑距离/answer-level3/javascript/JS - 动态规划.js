### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    // 动态规划
    // 问题描述: 左侧长度i -> 右侧长度j
    // 状态转移方程: dp(i,j) = min(dp(i-1,j)+1,dp(i,j-1)+1, dp(i-1,j-1) + worldi[i]!==wold2[j]?1:0)
    let len1 = word1.length;
    let len2 = word2.length;
    const dp = [];
    for (let i=0; i <= len1; i++) {
        dp[i] = [];
        for (let j=0; j <= len2; j++) {
            if (i === 0) {
                dp[i][j] = j;
            } else if (j === 0) {
                dp[i][j] = i;
            } else {
                dp[i][j] = Math.min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (word1[i-1] !== word2[j-1]));
            }
        }
    }
    return dp[len1][len2];
};
```