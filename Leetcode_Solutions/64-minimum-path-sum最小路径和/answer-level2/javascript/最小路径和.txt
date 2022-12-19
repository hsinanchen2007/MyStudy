边界判断:
- 最左上角: dp[0][0] = grid[0][0];
- 在左边界即i=0: dp[i][j] = dp[i][j-1] + grid[i][j];
- 在右边界即j=0: dp[i][j] = dp[i-1][j] + grid[i][j];
- 否则: dp[i][j] = Math.min(dp[i][j-1],dp[i-1][j]) + grid[i][j];
```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    if(!grid || !grid.length || !grid[0].length) return null;
    let m = grid.length;
    let n = grid[0].length;
    let dp= Array.from({length: m},() => new Array(n).fill(0))
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            if(i === 0 && j===0) {
                dp[i][j] = grid[0][0];
            } else if(i === 0) {
                dp[i][j] = dp[i][j-1] + grid[i][j]
            } else if(j === 0) {
                dp[i][j] = dp[i-1][j] + grid[i][j];
            }
            else {
                dp[i][j] = Math.min(dp[i][j-1],dp[i-1][j]) + grid[i][j];
            }
        }
    }
    return dp[m-1][n-1];
};
```
时间复杂度: O(mn)
空间复杂度: O(mn)