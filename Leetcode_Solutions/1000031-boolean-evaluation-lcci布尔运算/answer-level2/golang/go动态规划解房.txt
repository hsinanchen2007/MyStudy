### 解题思路

### 代码

```golang
func countEval(s string, result int) int {
	var dp [40][40][2]int
	l := len(s)
	for i := 0; i < l; i +=2{
		dp[i][i][int(s[i]-'0')] = 1
	}
	// printDP(&dp)
	// 区间宽度
	for i := 2; i < l + 1; i += 1{
		//区间起点
		for j := 0; j < l-i + 1; j += 1{
			// 区间运算符号的位置
			for k := j+1; k < i + j; k +=1 {
				getAns(s, j, k, i+j, &dp)
			}
		}
	}
	return dp[0][len(s)-1][result]

}


func getAns(s string, i, mid, j int, dp *[40][40][2]int){
	switch s[mid]{
	case '&':
		dp[i][j][0] += dp[i][mid-1][0] * dp[mid+1][j][0]
		dp[i][j][0] += dp[i][mid-1][1] * dp[mid+1][j][0]
		dp[i][j][0] += dp[i][mid-1][0] * dp[mid+1][j][1]
		dp[i][j][1] += dp[i][mid-1][1] * dp[mid+1][j][1]
	case '^':
		// 0
		dp[i][j][0] += dp[i][mid-1][0] * dp[mid+1][j][0]
		dp[i][j][0] += dp[i][mid-1][1] * dp[mid+1][j][1]
		// 1
		dp[i][j][1] += dp[i][mid-1][1] * dp[mid+1][j][0]
		dp[i][j][1] += dp[i][mid-1][0] * dp[mid+1][j][1]
	case '|':
		dp[i][j][1] += dp[i][mid-1][1] * dp[mid+1][j][0]
		dp[i][j][1] += dp[i][mid-1][0] * dp[mid+1][j][1]
		dp[i][j][1] += dp[i][mid-1][1] * dp[mid+1][j][1]
		dp[i][j][0] += dp[i][mid-1][0] * dp[mid+1][j][0]
	}
}
```