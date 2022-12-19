第一个人只能和 2 4 6 8... 握手
用dp计算中间人的握手次数
```
var mod = 1000000007
func numberOfWays(num_people int) int {
	dp := make([]int, num_people/2 + 1)
	dp[0], dp[1] = 1, 1
	for i := 2; i <= num_people/2; i++ {
		for j := 0; j < i; j++ {
			dp[i] = (dp[i] + dp[j] * dp[i-j-1])%mod
		}
	}
	return dp[num_people/2]
}


```
