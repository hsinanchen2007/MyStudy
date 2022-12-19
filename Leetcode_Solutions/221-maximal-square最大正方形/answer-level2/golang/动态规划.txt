dp(i, j)=min(dp(i−1, j), dp(i−1, j−1), dp(i, j−1))+1

```
func maximalSquare(matrix [][]byte) int {
	var row = len(matrix)
	if row == 0 {
		return 0
	}
	var col = len(matrix[0])
	var dp = make([][]int, row)
	var res int = 0

	// 初始化第一列
	for k := 0; k < row; k++ {
		tmp := make([]int, col)
		dp[k] = tmp
		if matrix[k][0] == '1' {
			dp[k][0] = 1
		} else {
			dp[k][0] = 0
		}
		if dp[k][0] > res {
			res = dp[k][0]
		}
	}
    // 初始化第一行
	for k := 0; k < col; k++ {
		if matrix[0][k] == '1' {
			dp[0][k] = 1
		} else {
			dp[0][k] = 0
		}

		if dp[0][k] > res {
			res = dp[0][k]
		}
	}
    
    // 从上往下，从左往右遍历
	for i := 1; i < row; i++ {
		for j := 1; j < col; j++ {
			if matrix[i][j] == '1' {
				dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
			} else {
				dp[i][j] = 0
			}

			if res < dp[i][j] {
				res = dp[i][j]
			}
		}
	}
	return res*res
}

func min(a, b, c int) (m int) {
	m = a
	if b < m {
		m = b
	}

	if c < m {
		m = c
	}
	return  // 需要显式return 
}
```