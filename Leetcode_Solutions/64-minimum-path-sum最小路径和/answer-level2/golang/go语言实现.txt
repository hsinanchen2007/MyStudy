### 解题思路
1、动态规划
2、最外边设置边界值

### 代码

```golang
package main

//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//说明：每次只能向下或者向右移动一步。
//
//示例:
//
//输入:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 7
//解释: 因为路径 1→3→1→1→1 的总和最小。
func minPathSum(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	var dp [][]int
	for i := 0; i < len(grid); i++ {
		var oneLinDp []int
		for j := 0; j < len(grid[0]); j++ {
			oneLinDp = append(oneLinDp, 0)
		}
		dp = append(dp, oneLinDp)
	}
	dp[0][0] = grid[0][0]
	for i := 1; i < len(grid); i++ {
		dp[i][0] = dp[i-1][0] + grid[i][0]
	}
	for i := 1; i < len(grid[0]); i++ {
		dp[0][i] = dp[0][i-1] + grid[0][i]
	}
	for i := 1; i < len(grid); i++ {
		for j := 1; j < len(grid[i]); j++ {
			if dp[i-1][j] > dp[i][j-1] {
				dp[i][j] = dp[i][j-1] + grid[i][j]
			} else {
				dp[i][j] = dp[i-1][j] + grid[i][j]
			}
		}
	}
	return dp[len(dp)-1][len(dp[0])-1]
}

```