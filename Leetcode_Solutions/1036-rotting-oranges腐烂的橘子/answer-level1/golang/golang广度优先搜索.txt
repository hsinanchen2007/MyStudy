```
	days := []int{}
	listx, listy := make([]int, 0), make([]int, 0)
	nums := 0
	for i := range grid {
		//  先遍历一遍 找到腐烂的橘子
		for j := range grid[i] {
			if grid[i][j] == 2 {
				listx = append(listx, i)
				listy = append(listy, j)
				nums++

			}
		}
	}
	days = append(days, nums)// days 列表存储第i天被感染的橘子数目。
	count := 0
	xindex, yindex := 0, 0
	for count <= len(days)-1 {
		nums = 0
		for days[count] > 0 {
			x, y := listx[xindex], listy[yindex]
			// 检查当前节点的上下左右是否有可以被感染的橘子，并保存他们的坐标 
			if x-1 >= 0 && x-1 < len(grid) && y >= 0 && y < len(grid[0]) && grid[x-1][y] == 1 {
				grid[x-1][y] = 2
				listx = append(listx, x-1)
				listy = append(listy, y)
				nums++
			}
			if x+1 >= 0 && x+1 < len(grid) && y >= 0 && y < len(grid[0]) && grid[x+1][y] == 1 {
				grid[x+1][y] = 2
				listx = append(listx, x+1)
				listy = append(listy, y)
				nums++
			}
			if x >= 0 && x < len(grid) && y-1 >= 0 && y < len(grid[0]) && grid[x][y-1] == 1 {
				grid[x][y-1] = 2
				listx = append(listx, x)
				listy = append(listy, y-1)
				nums++
			}
			if x >= 0 && x < len(grid) && y+1 >= 0 && y+1 < len(grid[0]) && grid[x][y+1] == 1 {
				grid[x][y+1] = 2
				listx = append(listx, x)
				listy = append(listy, y+1)
				nums++
			}
			days[count]-- // 相当于层次遍历。第count层就days[count]点。
			xindex++
			yindex++

		}
		if nums > 0 {
			// 如果nums 大于零 说明这一天感染了新的橘子，说明要继续。否则，说明走到了尽头，广度优先搜索进行最深了
			days = append(days, nums)
			count++
		} else {
			break
		}
	}
	for i := range grid {
		// 检查是否有未被感染的橘子
		for j := range grid[0] {
			if grid[i][j] == 1 {
				return -1
			}
		}
	}
	return count
```
