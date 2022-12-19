原理大体和上一题一样，这里相当于不加所有经过有障碍的路径
```javascript
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    if(!obstacleGrid || !obstacleGrid.length || !obstacleGrid[0].length) return 0;
    let m = obstacleGrid.length;
    let n = obstacleGrid[0].length;
    let dp = Array.from({length: m}, () => new Array(n).fill(0));
    dp[0][0] = 1;
    let iflag = false;
    let jflag = false;
    for(let i = 0; i < m;i++) {
        for (let j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0; // 所有经过这条路劲的都不通
                if (i == 0) iflag = true;  
                if (j == 0) jflag = true;
            } else if (i == 0) { // 边界判断
                dp[i][j] = iflag ? 0 : 1;
            } else if (j == 0) {
                dp[i][j] = jflag ? 0 : 1;
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    return dp[m-1][n-1]
};
```