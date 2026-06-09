### 代码

```javascript
var getRow = function(numRows) {
    if (numRows < 0) {
        return []
    }
    // 定义二维dp
    const dp = []
    for (let i = 1; i <= numRows + 1; i++) {
        dp.push(new Array(i).fill(null))
    }
    console.log(dp)
    // 处理子问题
    for (let i = 0; i < numRows + 1; i++) {
        for (let j = 0; j <= i; j++) {
            dp[i][0] = 1
            dp[i][j] = 1
        }
    }
    console.log(dp)
    // 处理状态转移方程
    for (let i = 2; i < numRows + 1; i++) {
        for (let j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
        }
    }
    return dp[numRows]
};
```