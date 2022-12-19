### 解题思路
Go +动态规划  dp[i][j]表示 i,j位置的最优解

可以从上往下规划，也可以从下往上规划，从下往上规划的话只需返回 dpp[0][0]即可，注意考虑边界条件
此处是从上往下规划

### 代码

```golang
func minimumTotal(triangle [][]int) int {
	if len(triangle) == 0 {
		return 0
	}
	dp := make([][]int, len(triangle))
	// 从上到下动态规划
	dp[0] = append(dp[0], triangle[0][0])
	for i := 1; i < len(triangle); i++ {
		dp[i] = make([]int, len(triangle[i]))
		// 开头和结尾要特殊处理
		dp[i][0] = dp[i-1][0]+triangle[i][0]
		for j := 1; j < i; j++ {
			// 计算每个dp的最优解
			dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j]
			// 计算返回值

		}
		dp[i][i] = dp[i-1][i-1] + triangle[i][i]

	}
	res:=math.MaxInt32
	l:=len(triangle)-1
	for i:=0;i<=l;i++{
		res=min(res,dp[l][i])
	}
	return res
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

```