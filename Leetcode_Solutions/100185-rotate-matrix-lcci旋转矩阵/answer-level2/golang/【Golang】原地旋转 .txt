在循环的过程中，计算出坐标，四个数字交换。

```go
func rotate(matrix [][]int) {
	size := len(matrix)

	if size <= 1 {
		return
	}

	for i := 0; i < size; i++ {
		a := size - 1 - i
		for j := i; j < a; j++ {
			b := size - 1 - j
			matrix[i][j], matrix[j][a], matrix[a][b], matrix[b][i] = matrix[b][i], matrix[i][j], matrix[j][a], matrix[a][b]
		}
	}
}
```
