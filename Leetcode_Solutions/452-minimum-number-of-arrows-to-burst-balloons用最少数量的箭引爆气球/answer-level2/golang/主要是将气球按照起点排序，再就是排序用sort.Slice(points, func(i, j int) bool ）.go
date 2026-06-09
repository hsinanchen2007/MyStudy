### 解题思路
此处撰写解题思路

### 代码

```golang
func findMinArrowShots(points [][]int) int {
	if len(points) == 0 {
		return 0
	}
	sort.Slice(points, func(i, j int) bool {
		if points[i][0] < points[j][0] {
			return true
		} else {
			return false
		}
	})

	shot := 1
	//shot_begin:=points[0][0]
	shot_end := points[0][1]
	for i := 1; i < len(points); i++ {
		if points[i][0] <= shot_end {
			//shot_begin=points[i][0]
			if points[i][1] < shot_end {
				shot_end = points[i][1]
			}
		} else {
			shot++
			//shot_begin=points[i][0]
			shot_end = points[i][1]
		}

	}
	return shot
}

```