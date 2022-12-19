### 解题思路
搜索标记可达位置

### 代码

```golang
var matrix [][]int
func movingCount(m int, n int, k int) int {
	matrix = make([][]int, m)
	for i := range matrix {
		matrix[i] = make([]int, n)
	}

	for i:=0; i<m; i++ {
		for j:=0; j<n; j++ {
			if bitSum(i, j) > k {
				matrix[i][j] = -1
			}
		}
	}

	matrix[0][0] = 1
	count := 1
	for i:=0; i<m; i++ {
		for j:=0; j<n; j++ {
			if i == 0 && j == 0 {
				continue
			}
			if matrix[i][j] == -1 {
				continue
			}
			if dfsTouch(i, j) {
				count++
			}
		}
	}
	return count
}

func dfsTouch(x, y int) bool {
	if x < 0 || y < 0 || x >= len(matrix) || y >= len(matrix[0]) {
		return false
	}
	if matrix[x][y] == -1 {
		return false
	}

	if matrix[x][y] == 1 {
		return true
	}

	matrix[x][y] = -1
	if dfsTouch(x,y-1) || dfsTouch(x-1, y) || dfsTouch(x+1, y) || dfsTouch(x, y+1) {
		matrix[x][y] = 1
		return true
	}
	return false
}

func bitSum(x, y int) int {
	res := 0
	for x > 0 {
		res += x%10
		x /= 10
	}
	for y > 0 {
		res += y%10
		y /= 10
	}
	return res
}
```