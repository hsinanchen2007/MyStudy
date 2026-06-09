先对矩阵做转置操作，然后每行逆序就是了，所有的操作直接在数组上进行交换就好。
主要是能想到变化规律，操作并不难。下面是Golang代码
```
func rotate(matrix [][]int) {
	n := len(matrix)
	// Transpose
	for i := 0; i < n; i++ {
		for j := 0; j <= i; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
	// Reverse each line
	for i := 0; i < n; i++ {
		p, q := 0, n-1
		for p < q {
			matrix[i][p], matrix[i][q] = matrix[i][q], matrix[i][p]
			p++
			q--
		}
	}
}
```
时间复杂度主要取决于第一步交换，至少遍历一半元素，O(N*N)