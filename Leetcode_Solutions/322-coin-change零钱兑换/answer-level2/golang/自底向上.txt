

```

// 自底向上动态规划  dp[s]:表示s金额对应的最小组合数量，dp[s] = min(1<i<n)dp[s-ci] + 1
func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)

	for i := 1; i <= amount; i++ {
		min := 2*amount
		for _, val := range coins {
			if val > i {
				continue
			}
			if dp[i-val] == -1 {
				continue
			}
			if dp[i-val] + 1 < min {
				min = dp[i-val] + 1
			}
		}
		if min == 2*amount {
			dp[i] = -1
		} else {
			dp[i] = min
		}

	}
	return dp[amount]
}
```