```javascript []
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
	const m = obstacleGrid[0].length;
	// 默认为0, 第一行情况可以写成，dp[j] = dp[j] + dp[j - 1]
	const dp = Array(m).fill(0);
	// 特殊情况[0, 0], 记为1
	dp[0] = 1;

	obstacleGrid.forEach((row) => {
		row.forEach((vo, j) => {
			if (j !== 0) {
				// 同 62. 不同路径 状态转移方程
				dp[j] += dp[j - 1];
			}
			// 如果当前有障碍物，则到此处的路线为0
			dp[j] *= (1 - vo);
		});
	});
	return dp[m - 1];
};
```

- 时间复杂度 *O(n²)*
- 空间复杂度 *O(n)*

