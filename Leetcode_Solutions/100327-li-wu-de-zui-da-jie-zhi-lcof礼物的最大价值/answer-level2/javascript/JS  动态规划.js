### 代码

```javascript
var maxValue = function(grid) {
    if(grid == null || grid.length < 1) return 0;
    const row = grid.length;
    const col = grid[0].length;
    // 新建二维dp
    const dp = [];
    for(let i = 0; i < row; i++){
        let item = new Array(col).fill(null);
        dp.push(item)
    }
    // 初始值
    dp[0][0] = grid[0][0]
    for(let j = 1; j < col; j++){
        dp[0][j] = grid[0][j] + dp[0][j - 1]
    }
    for(let i = 1; i < row; i++){
        dp[i][0] = grid[i][0] + dp[i - 1][0]
    }
    // 状态转移方程
    for(let i = 1; i < row; i++){
        for(let j = 1; j <col; j++){
            dp[i][j] = grid[i][j] + Math.max(dp[i][j - 1], dp[i - 1][j])
        }
    }
    return dp[row - 1][col - 1]
};
```