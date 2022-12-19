- 计算机是从0开始的，例如:m=3, n=2，我们只要向下 1 步，向右 2 步就一定能到达终点
- m为0或n为0都只有一条路可走
- 最终返回值是dp[m-1][n-1]

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    let dp = Array.from({length:m},()=>new Array(n).fill(0));
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            if(i===0 || j===0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
            }
        }
    }
    return dp[m-1][n-1];
};
```
时间复杂度：O(m*n)
空间复杂度：O(m*n)