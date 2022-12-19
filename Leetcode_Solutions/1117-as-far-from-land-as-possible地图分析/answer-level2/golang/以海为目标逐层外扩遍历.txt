思路相对比较简单，但是需要注意边界值处理，注意细节！
```
func maxDistance(grid [][]int) int {
	var max = -1
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			// 广搜
			if grid[i][j] == 1 {
				continue
			}
			res := search(grid, i, j)
			if res > max {
				max = res
			}
		}
	}
	return max
}

func search(grid [][]int, x, y int) int {
	length := 2*(len(grid)-1)
	for i := 1; i <= length; i++ {
		for k := -1*i; k <= i; k++ {
			r := x+k;
			if r >= 0 && r < len(grid) {
				c1 := i - int(math.Abs(float64(k)))
				c2 := int(math.Abs(float64(k))) - i
				if c1+y >= 0 && c1+y < len(grid) {
					if grid[r][c1+y] == 1 {
						return i
					}
				}
				if c2+y >= 0 && c2+y < len(grid) {
					if grid[r][c2+y] == 1{
						return i
					}

				}
			}
		}

	}
	return -1
}
```