原地修改，空间复杂度$O(n)$
```golang
func minimumTotal(triangle [][]int) int {
	r := len(triangle)
	if r == 0 {
		return 0
	}
	lastRow := r - 1
	if r == 1 {
		return triangle[0][0]
	}
	min := math.MaxInt32
	for i := 1; i < r; i++ {
		c := len(triangle[i])
		ll := triangle[i][1]
		for j := 1; j < c; j++ {
			if j > 1 {
				triangle[i][j-1] = int(math.Min(float64(triangle[i-1][j-1]+ll), float64(triangle[i][j-1])))
				ll = triangle[i][j]
				triangle[i][j] = triangle[i-1][j-1] + triangle[i][j]

			} else {
				ll = triangle[i][j]
				triangle[i][j-1] = triangle[i-1][j-1] + triangle[i][j-1]
				triangle[i][j] = triangle[i-1][j-1] + triangle[i][j]
			}

			if lastRow == i {
				min = int(math.Min(float64(min), float64(triangle[i][j-1])))
				min = int(math.Min(float64(min), float64(triangle[i][j])))
			}
		}
	}

	return min
}
```
