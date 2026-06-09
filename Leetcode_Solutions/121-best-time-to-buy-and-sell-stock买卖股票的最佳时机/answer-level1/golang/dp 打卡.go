### 解题思路
动态规划

### 代码

```golang
func max(x, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}

func maxProfit(prices []int) int {
	n := len(prices)
	if n == 0 {
		return 0
	}

	dp := [][2]int{}
	dp_0 := [2]int{0,-prices[0]}
	dp=append(dp,dp_0)
	for i := 1; i < n; i++ {
		tmp:=[2]int{}
		tmp[0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
		tmp[1] = max(dp[i-1][1], -prices[i])
		dp=append(dp,tmp)
	}
	return dp[n-1][0]
}

```