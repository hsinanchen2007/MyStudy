```
const (
	charDelete = 'X'
	charIsland = '1'
	charWater  = '0'
)

func numIslands(grid [][]byte) int {
	var (
		i, j, lengthY, count int
		lengthX              = len(grid)
	)
	if lengthX == 0 {
		return 0
	}
	lengthY = len(grid[0])
	for i = 0; i < lengthX; i++ {
		for j = 0; j < lengthY; j++ {
			if grid[i][j] == charIsland {
				count++
				travelIsland(grid, i, j, lengthX, lengthY)
			}
		}
	}

	return count
}

func travelIsland(grid [][]byte, x, y, lenX, lenY int) bool {
	if grid[x][y] == charIsland {
		grid[x][y] = charDelete
	} else {
		return false
	}
	for i := -1; i+x >= 0; i-- {
		if !travelIsland(grid, i+x, y, lenX, lenY) {
			break
		}
	}
	for i := 1; i+x < lenX; i++ {
		if !travelIsland(grid, i+x, y, lenX, lenY) {
			break
		}
	}
	for i := 1; i+y < lenY; i++ {
		if !travelIsland(grid, x, y+i, lenX, lenY) {
			break
		}
	}
	for i := -1; i+y >= 0; i-- {
		if !travelIsland(grid, x, y+i, lenX, lenY) {
			break
		}
	}
	return true
}
```
