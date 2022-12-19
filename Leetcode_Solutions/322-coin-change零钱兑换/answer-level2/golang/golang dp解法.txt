### 解题思路
dp[i] = MIN(dp[i-j])+1,其中，j∈{coins}

### 代码
执行用时 :12 ms, 在所有 Go 提交中击败了75.94%的用户
内存消耗 :6 MB, 在所有 Go 提交中击败了81.75%的用户
```golang

func coinChange(coins []int, amount int) int {
	if len(coins) == 0 {
		return -1
	}
	dp := make([]int, amount+1)
	availableCoins := make([]int, 0)
	for _, coin := range coins {
		if coin > amount {
			continue
		}
		availableCoins = append(availableCoins, coin)
		dp[coin] = 1
	}
	for i := 1; i < len(dp); i++ {
		if dp[i] != 0 {
			continue
		}
		dp[i] = -1
		for _, coin := range coins {
			lastIdx := i-coin
			if lastIdx <= 0 || dp[lastIdx] == -1{
				continue
			}
			if dp[i] == -1 || (dp[i] != -1 && dp[lastIdx]+1 < dp[i]) {
				dp[i] = dp[lastIdx]+1
			}
		}
	}
	return dp[amount]
}
```