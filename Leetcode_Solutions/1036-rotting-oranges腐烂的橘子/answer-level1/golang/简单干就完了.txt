func orangesRotting(grid [][]int) int {

    time := 0

	for {
		haojz := 0 //好橘子数量
		crcount := 0 //传染数量
		mm := [][]int{} //坏橘子位置
		for i := 0; i < len(grid); i++ {
			for j := 0; j < len(grid[i]); j++ {
				if grid[i][j] == 1 {
					haojz++
				} else if grid[i][j] == 2 {
					mm = append(mm, []int{i, j})
				}
			}
		}
        //每个坏橘子去传染  这里可以记录下传染过的坏橘子不用继续传染
        // 可以使用 map[string]bool   string为"i,j"
		for _, v := range mm {
			i := v[0]
			j := v[1]
			//chuanran
			if i > 0 {
				if grid[i-1][j] == 1 {
					crcount++
					grid[i-1][j] = 2
				}
			}
			if i < len(grid)-1 {
				if grid[i+1][j] == 1 {
					crcount++
					grid[i+1][j] = 2
				}
			}
			if j > 0 {
				if grid[i][j-1] == 1 {
					crcount++
					grid[i][j-1] = 2
				}
			}
			if j < len(grid[0])-1 {
				if grid[i][j+1] == 1 {
					crcount++
					grid[i][j+1] = 2
				}
			}
		}
        // 如果一个都没传染到 就结束了
		if crcount == 0 {
			if haojz == 0 {
				return time
			} else {
				return -1
			}
		} else {
            //传染到了 继续
			time++
		}

	}
}