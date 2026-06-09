```
func cuttingRope(n int) int {
	dp := make([]int,n + 1)
	dp[1] = 1
	dp[2] = 1
	for i := 3 ; i <= n ; i++{
		maxDp := dp[i-1]
		for j := 1 ; j < i - 1 ; j ++{
			maxDp =  max(max(j,dp[j]) * max(i-j,dp[i-j]) , maxDp)
		}
		dp[i] = maxDp
	}
	return dp[n]
}

func max(a,b int) int{
	if a > b {
		return a
	}
	return b
}
```
