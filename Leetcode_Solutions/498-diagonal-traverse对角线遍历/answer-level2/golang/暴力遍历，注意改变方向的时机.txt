**up 往右上角遍历标记为true，往左下角遍历时标记位false，x表示横轴，y表示纵轴，当x，y任一一个遍历到0时或者遍历到横轴或者纵轴最大位置时，改变方向，暴力遍历**
```
func findDiagonalOrder(matrix [][]int) []int {
	result := []int{}
	if len(matrix) == 0 {
		return result
	}
	m := len(matrix)
	n := len(matrix[0])
	x,y,i := 0,0,0
	up := true
	for i < m*n {
		i++
		result = append(result, matrix[y][x])
		if up {
			if x < n - 1 {
				x++
				if y <= 0 {
					up = false
				}else {
					y--
				}
			}else {
				x = n -1
				y++
				up = false
			}
		}else {
			if y < m - 1 {
				y++
				if x<= 0 {
					up = true
				}else {
					x--
				}
			}else {
				y = m - 1
				x++
				up = true
			}
		}
	}
	return result
}
```

