### 解题思路
定义: dp[i][j]表示到达i，j坐标所需的步数
能到达右下角的路径只有2条，一条是从上面往下走，一条是从左边往右走，因此很容易得到 dp[i][j] = dp[i-1][j]+dp[i][j-1]

### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
     let dp = Array.from(new Array(m+1),() => new Array(n+1).fill(0))
   for (let i = 0; i < m; i++) {
     dp[i][0] = 1
   }
   for (let j = 0; j < n; j++) {
     dp[0][j] = 1
   }
    for(let i = 1;i<m;i++){
      for(let j= 1;j<n;j++){
        dp[i][j] = dp[i-1][j]+dp[i][j-1]
      }
    }
    return dp[m-1][n-1]
};
```