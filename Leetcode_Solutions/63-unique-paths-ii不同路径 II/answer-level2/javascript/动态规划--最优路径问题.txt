
动态规划中的一类问题：加边界的二维数组，进行记忆化搜索，求解最优路径

## 最优子结构

dp[i][j]表示到达i，j共有的路径数(0<=i<=m, 0<=j<=n)

## 动态转换方程

如果当前位置为障碍物，即grid[i-1][j-1] == 1, 则有dp[i][j] = 0
如果当前位置可走，即grid[i-1][j-1] == 0, 则有dp[i][j] = dp[i-1][j] + dp[i][j-1]

## 边界条件

- i==0, j==0时，为抽象出的边界，有dp[0...m] = 0, dp[0...n] = 0
- 出发点dp[1][1] = 1

## 代码实现：

```javascript
var uniquePathsWithObstacles = function(grid) {
    let m = grid.length, n = grid[0].length
    let dp = []
    for (let i =0; i<=m; i++) dp[i] = new Array(n+1).fill(0)
    if (grid[0][0] == 1) return 0
    dp[1][1] = 1
    for (let i = 1; i<=m ; i++){
        for (let j = 1; j<=n; j++){
            if (i==1 && j ==1) continue
            if (grid[i-1][j-1] ==1) dp[i][j]=0
            else dp[i][j] = dp[i-1][j]+ dp[i][j-1]
        }
    }
    return dp[m][n]
};
```

---

## 类似题目

- 62. 不同路径.md
- 63. 不同路径 II.md
- 64. 最小路径和.md
- 72. 编辑距离.md

上述问题均可抽象为二维数组存储中间求解过程，最终得到最优解，可视为同一类求解最优路径的问题

欢迎关注[muyids的leetcode题解](https://github.com/muyids/leetcode)