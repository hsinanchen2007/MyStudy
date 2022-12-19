```go
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	// dp[i][j] 表示[0,0] 到 [i,j] 有多少种方法，每次只能从左边或者上面来
	// dp[i][j] = dp[i-1][j] + dp[i][j-1]
	if obstacleGrid[0][0] == 1 {
		return 0
	}

	obstacleGrid[0][0] = 1

	m, n := len(obstacleGrid), len(obstacleGrid[0])
	for i := 1; i < m; i++ {
		if obstacleGrid[i][0] == 1 { // 有一个障碍，后面的都去不了
			for j := i; j < m; j++ {
				obstacleGrid[j][0] = 0
			}
			break
		}
		obstacleGrid[i][0] = 1
	}
	for i := 1; i < n; i++ {
		if obstacleGrid[0][i] == 1 { // 有一个障碍，后面的都去不了
			for j := i; j < n; j++ {
				obstacleGrid[0][j] = 0
			}
			break
		}
		obstacleGrid[0][i] = 1
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if obstacleGrid[i][j] == 1 {
				obstacleGrid[i][j] = 0
			} else {
				obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
			}
		}
	}
	return obstacleGrid[m-1][n-1]
}

/*
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	// dp[i][j] 表示[0,0] 到 [i,j] 有多少种方法，每次只能从左边或者上面来
	// dp[i][j] = dp[i-1][j] + dp[i][j-1]
	if obstacleGrid[0][0] == 1 {
		return 0
	}

	m, n := len(obstacleGrid), len(obstacleGrid[0])
	dp := make([][]int, m)
	flag := false
	for i := range dp {
		dp[i] = make([]int, n)
		if obstacleGrid[i][0] == 1 {
			flag = true
		}
		if flag == false {  // 有石头阻挡就过不了了
			dp[i][0] = 1
		}
	}

	for i := 0; i < n; i++ {
		if obstacleGrid[0][i] == 1 {
			break
		}
		dp[0][i] = 1
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if obstacleGrid[i][j] == 1 {
				dp[i][j] = 0
			} else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1]
			}
		}
	}
	return dp[m-1][n-1]
}
*/
```