### 解题思路
此处撰写解题思路

### 代码

```golang
func rotate(matrix [][]int)  {
	N := len(matrix)

	for y := 0; y < (N / 2); y++ {
		matrix[y], matrix[N-1-y] = matrix[N-1-y], matrix[y]
	}

	for y := 0; y < N; y++ {
		for x := 0; x < y; x++ {
			matrix[y][x], matrix[x][y] = matrix[x][y], matrix[y][x]
		}
	}
}
```