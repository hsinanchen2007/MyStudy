### 解题思路
先上下反转，然后沿对角线反转即可

### 代码

```golang
// 先上下反转，然后沿对角线反转即可
func rotate(matrix [][]int) {
	l := len(matrix)
	// 特殊情况处理
	if l == 0 || l == 1 {
		return
	}
	// 上下反转
	i, j := 0, l-1
	for i < j {
		for k := 0; k < len(matrix[i]); k++ {
			matrix[i][k], matrix[j][k] = matrix[j][k], matrix[i][k]
		}
		i++
		j--
	}
	// 斜对称反转
	for i = 0; i < l; i++ {
		for j = 0; j < i; j++ {
			if i != j {
				matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
			}
		}
	}
}
```