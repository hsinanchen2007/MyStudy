### 解题思路
1、思考 BFS 和 DFS的区别

### 代码

```golang
func maxAreaOfIsland(grid [][]int) int {
	var maxArea = 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == 1 {
				area := GetArea(grid, i, j)
				if area > maxArea {
					maxArea = area
				}
			}
		}
	}
	return maxArea
}

func GetArea(grid [][]int, x, y int) int {
	if x == len(grid) || x < 0 {
		return 0
	} else if y == len(grid[0]) || y < 0 {
		return 0
	}
	if grid[x][y] == 1 {
		grid[x][y] = 0
		return 1 + GetArea(grid, x+1, y) + GetArea(grid, x-1, y) + GetArea(grid, x, y+1) + GetArea(grid, x, y-1)
	}
	return 0
}
```