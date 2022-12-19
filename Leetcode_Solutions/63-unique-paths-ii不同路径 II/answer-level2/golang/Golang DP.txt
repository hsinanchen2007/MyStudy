需要注意的一点是第一行和第一列如果遇到障碍物则其后的所有格子皆不可达，最大路径数值置为0
```
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
   
 if obstacleGrid[0][0] == 1 {
		return 0
	}
	if obstacleGrid[len(obstacleGrid)-1][len(obstacleGrid[0])-1] == 1 {
		return 0
	}
	mem := [][]int{}
	allzero := false
	for i := 0; i < len(obstacleGrid); i++ {
		tmp := make([]int, len(obstacleGrid[0]))
		if obstacleGrid[i][0] != 1 && !allzero {
			tmp[0] = 1
		} else {
			allzero = true
			tmp[0] = 0
		}

		mem = append(mem, tmp)
	}
	allzero = false
	for j := 0; j < len(obstacleGrid[0]); j++ {
		if obstacleGrid[0][j] != 1 && !allzero {
			mem[0][j] = 1
		} else {
			allzero = true
			mem[0][j] = 0
		}

	}
	for row := 1; row < len(obstacleGrid); row++ {
		for col := 1; col < len(obstacleGrid[0]); col++ {
			if obstacleGrid[row][col] != 1 {
				mem[row][col] = mem[row-1][col] + mem[row][col-1]
			} else {
				mem[row][col] = 0
			}

		}
	}
	return mem[len(obstacleGrid)-1][len(obstacleGrid[0])-1]
}
```
