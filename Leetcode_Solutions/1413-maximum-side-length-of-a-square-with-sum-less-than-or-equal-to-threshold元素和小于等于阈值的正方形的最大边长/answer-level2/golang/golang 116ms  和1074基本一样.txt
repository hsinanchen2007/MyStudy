和1074基本一样, 详细解答可以去看一下1074
```
func maxSideLength(mat [][]int, threshold int) int {
	n, m := len(mat), len(mat[0])
	sum := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		sum[i] = make([]int, m+1)
	}
	for i := 0; i < n; i++ {
		t := 0
		for j := 0; j < m; j++ {
			t += mat[i][j]
			sum[i+1][j+1] = t + sum[i][j+1]
		}
	}
	max := 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			for k := 0; i+k <= n && j+k <= m; k++ {
				x, y := i+k, j+k
				v := sum[x][y] - sum[i-1][y] - sum[x][j-1] + sum[i-1][j-1]
				if v <= threshold && max < k+1 {
					max = k + 1
				}
				if v >= threshold {
					break
				}
			}
		}
	}
	return max
}
```
