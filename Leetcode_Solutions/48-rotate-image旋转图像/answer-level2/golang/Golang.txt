```
func rotate(matrix [][]int)  {
    for i := range matrix {
		for j := range matrix[i] {
			if i < j {
				matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
			}
		}
	}

	for i := range matrix {
		for j := range matrix[i] {
			if j < len(matrix[i])/2 {
				matrix[i][j], matrix[i][len(matrix[i])-1-j] = matrix[i][len(matrix[i])-1-j], matrix[i][j]
			}
		}
	}
}
```
