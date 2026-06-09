func minCost(costs [][]int) int {
	if len(costs) == 0 {
		return 0
	}

	n := len(costs)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, 3)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < 3; j++ {
			if i == 0 {
				dp[i][j] = costs[i][j]
				continue
			}
			if j == 0 {
				dp[i][j] = int(math.Min(float64(dp[i-1][1]), float64(dp[i-1][2]))) + costs[i][j]
			}
			if j == 1 {
				dp[i][j] = int(math.Min(float64(dp[i-1][0]), float64(dp[i-1][2]))) + costs[i][j]
			}
			if j == 2 {
				dp[i][j] = int(math.Min(float64(dp[i-1][0]), float64(dp[i-1][1]))) + costs[i][j]
			}

		}
	}

	min := int(math.Min(float64(dp[n-1][0]), float64(dp[n-1][1])))
	return int(math.Min(float64(min), float64(dp[n-1][2])))
}
