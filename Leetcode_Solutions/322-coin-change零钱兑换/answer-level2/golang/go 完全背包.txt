```
func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)
	for i := 1; i <= amount; i++ {
		dp[i] = -1
		for _, coin := range coins {
			if i > coin && dp[i-coin] != -1 {
				if dp[i] > dp[i-coin]+1 || dp[i] == -1 {
					dp[i] = dp[i-coin] + 1
				}
			}
			if i == coin {
				dp[i] = 1
			}
		}
	}
	return dp[amount]
}
```
