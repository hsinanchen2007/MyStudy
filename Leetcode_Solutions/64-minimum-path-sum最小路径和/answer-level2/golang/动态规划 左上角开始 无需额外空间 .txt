### 解题思路
此处撰写解题思路
从左上角开始 因为要么向下 要么想右

比较特殊的是左边界和上边界的最小值的计算

最后直接遍历到最后一个终点坐标
### 代码

```golang
func minPathSum(grid [][]int) int {
	nr := len(grid)
	nc := len(grid[0])
	for i := 0; i < nr; i++ {
		for j := 0; j < nc; j++ {
			if i == 0 && j == 0 {
				continue
			} else if i == 0 {
				grid[i][j] = grid[i][j-1] + grid[i][j]
			} else if j == 0 {
				grid[i][j] = grid[i-1][j] + grid[i][j]
			} else {
				if grid[i-1][j] < grid[i][j-1] {
					//上面最小
					grid[i][j] = grid[i-1][j] + grid[i][j]
				} else {
					//左边最小
					grid[i][j] = grid[i][j-1] + grid[i][j]
				}
			}
		}
	}
	return grid[nr-1][nc-1]
}
```