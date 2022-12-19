### 解题思路
不难，直接看代码就可以了

### 代码

```javascript
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    //dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    const xLen = obstacleGrid.length;
    if(!xLen) return 0;
    const yLen = obstacleGrid[0].length;
    let dp = [];
    for(let i = 0; i < xLen + 2; i ++) {
        let arr = new Array(yLen + 2).fill(0);
        dp.push(arr);
    }
    dp[1][0] = 1;
    for(let i = 1; i < xLen + 1; i ++) {
        for(let j = 1; j < yLen + 1; j ++) {
            if(obstacleGrid[i - 1][j - 1] === 1) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    // console.log(dp);
    return dp[xLen][yLen];
};
```