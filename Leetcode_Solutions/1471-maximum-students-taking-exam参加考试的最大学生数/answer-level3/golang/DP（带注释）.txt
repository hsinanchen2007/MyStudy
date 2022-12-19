```
func maxStudents(seats [][]byte) int {
	var (
		// 某一行中处于 state i 时，可以坐 stateCount[i] 个学生
		stateCount = make([]int, 256)
		//  前 i 排在第 i 排处于 state j 时可以坐 lineStateCount[i][j] 个学生
		lineStateCount = make([][]int, 9)
		badSeats       = make([]int, 9)
		lenX           = len(seats)
		lenY           = len(seats[0])
		i, j, k        int
		ans            = 0
	)
	for i = 1; i < 256; i++ {
		stateCount[i] = stateCount[i>>1] + (i & 1)
	}
	for i = 0; i <= lenX; i++ {
		lineStateCount[i] = make([]int, 256)
		//for j = 0; j < 256; j++ {
		//	lineStateCount[i][j] = 0
		//}
	}
	for i = 0; i < lenX; i++ {
		badSeats[i] = 0
		for j = 0; j < lenY; j++ {
			if seats[i][j] == '#' {
				badSeats[i] |= 1 << j
			}
		}
	}
	lineStateCount[0][0] = 0
	for i = 0; i < lenX; i++ {
		// 对于第 i 排的 state j 作判断
		for j = 0; j < 1<<lenY; j++ {
			// 没有坏座位： j&badSeats[i] == 0
			// 对于每个坐了人的座位，左右都没有人：j&j>>1 == 0 && j&j<<1 == 0
			if j&badSeats[i] == 0 && j&(j>>1) == 0 && j&(j<<1) == 0 {
				for k = 0; k < 1<<lenY; k++ {
					// 对于每个坐了人的座位，左前和右前都没有人
					if j&(k>>1) == 0 && j&(k<<1) == 0 {
						// stateCount[j]：状态 j 下可以这一排可以坐多少人
						lineStateCount[i+1][j] = max(lineStateCount[i+1][j], lineStateCount[i][k]+stateCount[j])
					}
				}
			}
		}
	}
	for i = 0; i < 1<<lenY; i++ {
		ans = max(ans, lineStateCount[lenX][i])
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```

重构的： https://leetcode.com/contest/weekly-contest-175/ranking，第一名的写法。