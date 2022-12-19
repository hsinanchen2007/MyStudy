常规做法没什么好说的
```js
var maxValue = function(grid) {
    if (!grid.length) return 0;
    const col = grid[0].length;
    const dp = [];
    dp[0] = [];
    dp[0][0] = grid[0][0];
    for(let i = 1; i < grid.length; i++) {
        dp[i] = [];
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for(let i = 1; i < col; i++) {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for(let i = 1; i < grid.length; i++) {
        for(let j = 1; j < col; j++) {
            dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        }
    }
    return dp[grid.length - 1][col - 1];
};
```
