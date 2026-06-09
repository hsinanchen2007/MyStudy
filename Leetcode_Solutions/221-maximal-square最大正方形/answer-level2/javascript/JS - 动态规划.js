### 解题思路
递推, 递归可解(后面的解 和 前面解之间的转换公式),前面解暂存(有空间优化的空间),往往通过空间来换时间

### 代码

```javascript
/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function(matrix) {
    let rows = matrix.length;
    let cols = rows > 0 ? matrix[0].length : 0;
    let maxLen = 0;
    // 基于j(列的状态暂存)
    let dp = [];
    for (let j=0; j<cols; j++) {
        dp[j] = 0;
    }
    let prev = 0;
    for (let i=0; i<rows; i++) {
        for (let j=0; j<cols; j++) {
            let temp = dp[j];
            if (matrix[i][j] === '1') {
                dp[j] = Math.min(dp[j], dp[j -1]||0,prev) + 1;
                maxLen = Math.max(maxLen, dp[j]);
            } else {
                dp[j] = 0;
            }
            prev = temp;
        }
    }
    return maxLen * maxLen;
};
```