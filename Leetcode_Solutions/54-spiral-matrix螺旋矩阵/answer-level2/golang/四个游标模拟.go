

```
func spiralOrder(matrix [][]int) []int {
	res := []int{}
	if len(matrix) == 0 {
		return res
	}
	if len(matrix[0]) == 0 {
		return res
	}
	r1, c1 := 0, 0
	r2, c2 := len(matrix)-1, len(matrix[0])-1
	for r1 <= r2 && c1 <= c2 {
		for i := c1; i <= c2; i++ {
			res = append(res, matrix[r1][i])
		} 
		for i := r1+1; i <= r2; i++ {
			res = append(res, matrix[i][c2])
		}
		
		if r1 < r2 && c1 < c2 {
			for i := c2-1; i >= c1; i-- {
				res = append(res, matrix[r2][i])
			}
			for i := r2-1; i> r1; i-- {
				res = append(res, matrix[i][c1])
			}
		}
		r1++
		r2--
		c1++
		c2--
	}

	return res
}
```