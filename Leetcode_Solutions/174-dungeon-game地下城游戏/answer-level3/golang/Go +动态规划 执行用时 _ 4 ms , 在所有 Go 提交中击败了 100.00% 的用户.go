### 解题思路
动态规划，从右下角往上规划

// dunxy表示当前最小需要的血量，dunxy_next表示下个节点至少需要的血量，cur表示当前节点的血量值，加或者减
// dunxy+cur>=dunxy_nexy &&dunxy>=1  -----> dunxy>=dunxy_nexy-cur&&dunxy>=1 所以  dunxy=max(dunxy_nexy-dunxy,1)

### 代码

```golang
func calculateMinimumHP(dungeon [][]int) int {
	if len(dungeon) == 0 || len(dungeon[0]) == 0 {
		return 0
	}
	row := len(dungeon)
	column := len(dungeon[0])
	dp := make([][]int, row)
	for i := 0; i < row; i++ {
		dp[i] = make([]int, column)
	}
	// cur表示当前最小需要的血量，dunxy_next表示下个节点至少需要的血量，
	// dunxy+cur>=dunxy_nexy &&dunxy>=1  -----> dunxy>=dunxy_nexy-cur&&dunxy>=1 所以  dunxy=max(dunxy_nexy-dunxy,1)
	dp[row-1][column-1] = max(1-dungeon[row-1][column-1], 1)
	//最后一行
	for i := column - 2; i >= 0; i-- {
		dp[row-1][i] = max(dp[row-1][i+1]-dungeon[row-1][i], 1)
	}
	// 最后一列
	for i := row - 2; i >= 0; i-- {
		dp[i][column-1] = max(dp[i+1][column-1]-dungeon[i][column-1], 1)
	}
	// 中间的

	for i := row - 2; i >= 0; i-- {
		for j := column - 2; j >= 0; j-- {
			dpmin := min(dp[i][j+1], dp[i+1][j])
			dp[i][j] = max(dpmin-dungeon[i][j], 1)
		}
	}
	return dp[0][0]
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

```