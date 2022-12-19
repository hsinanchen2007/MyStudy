dp[i][j] = int(math.Min(math.Min(float64(dp[i-1][j]), float64(dp[i][j-1])), float64(dp[i-1][j-1]))) + 1 方程式

dp[i][j] 表示正方形的右下角的点 
当matrix[i][j] = 0时 dp[i][j] = 0
当matrix[i][j] = 1时 dp[i][j] = 要取方程式的值

```
func maximalSquare(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}

	dp := make([][]int, len(matrix))

	for idx, v := range matrix {
		dp[idx] = make([]int, len(v))
	}

	var zero byte = '0'

	m := 0
	for idx, v := range matrix[0] {
		if v == zero {
			dp[0][idx] = 0
		}else {
			dp[0][idx] = 1
		}
        if dp[0][idx] > m {
			m = dp[0][idx]
		}
	}

	for i := 0; i < len(matrix); i++ {
		v := matrix[i][0]
		if v == zero {
			dp[i][0] = 0
		}else {
			dp[i][0] = 1
		}
        if dp[i][0] > m {
			m = dp[i][0]
		}
	}

	for i := 1; i < len(matrix); i++ {
		for j := 1; j < len(matrix[0]); j++ {
			if matrix[i][j] == '1' {
                dp[i][j] = int(math.Min(math.Min(float64(dp[i-1][j]), float64(dp[i][j-1])), float64(dp[i-1][j-1]))) + 1
                if dp[i][j] > m {
                    m = dp[i][j]
                }
			}else {
				dp[i][j] = 0
			}
		}
	}

	return m * m
}
```
