```go

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	if len(obstacleGrid) == 0 || len(obstacleGrid[0]) == 0 {
		return 0
	}

	m := len(obstacleGrid)
	n := len(obstacleGrid[0])

	if obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1 {
		return 0
	}

	res := make([][]int, m)

	for x := 0; x < m; x++ {
		xArr := make([]int, n)
		res[x] = xArr
		for y := 0; y < n; y++ {
            //起点
			if x == 0 && y == 0 {
				xArr[y] = 1
            //处理两个边缘路线
			} else if x == 0 {
				if obstacleGrid[x][y] == 1 || res[x][y-1] == 0 {
					xArr[y] = 0
				} else {
					xArr[y] = 1
				}
            //处理两个边缘路线
			} else if y == 0 {
				if obstacleGrid[x][y] == 1 || res[x-1][y] == 0 {
					xArr[y] = 0
				} else {
					xArr[y] = 1
				}
			} else {
				if obstacleGrid[x][y] == 1 ||  (res[x-1][y] == 0 && res[x][y-1] == 0) {
					xArr[y] = 0
				} else {
                    //这里直接加， 0 + n = n
					xArr[y] = res[x-1][y]+res[x][y-1]
				}
			}
		}
	}
	return res[m-1][n-1]
}

```