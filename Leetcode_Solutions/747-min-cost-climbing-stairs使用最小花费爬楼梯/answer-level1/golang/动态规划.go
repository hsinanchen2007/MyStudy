### 解题思路
此处撰写解题思路

### 代码

```golang
//dp[k]代表登上第k级台阶所消耗的体力值，包括 台阶k自己要消耗的体力值，当的登顶时，只能是由 cost[length-1]登上来，或者是cost[length-2]登上来，顶部没有定义台阶自己所需要的消耗体力
func minCostClimbingStairs(cost []int) int {
	dp:=make([]int, len(cost))
	dp[0]=cost[0]
	dp[1]=cost[1]
	for i:=2;i< len(cost);i++{
		dp[i]=int(math.Min(float64(dp[i-1]),float64(dp[i-2])))+cost[i]
	}
	return int(math.Min(float64(dp[len(cost)-1]),float64(dp[len(cost)-2])))
}
```