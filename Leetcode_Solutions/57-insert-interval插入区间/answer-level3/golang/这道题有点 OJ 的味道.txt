```
func insert(intervals [][]int, newInterval []int) (rst [][]int) {
	var begin = -1
	var end = -1
	var ever = false

	if len(intervals) == 0 {
		return [][]int{newInterval}
	}
	if newInterval[1] < intervals[0][0] {
		return append([][]int{newInterval}, intervals...)
	}
	if newInterval[0] > intervals[len(intervals)-1][1] {
		return append(intervals, newInterval)
	}

	for i := 0; i < len(intervals); i++ {
		if intervals[i][1] < newInterval[0] {
			rst = append(rst, intervals[i])
			continue
		}
		if intervals[i][0] > newInterval[1] {
			if begin != -1 {
				ever = true
				if intervals[begin][0] > newInterval[0] {
					intervals[begin][0] = newInterval[0]
				}
				if intervals[end][1] < newInterval[1] {
					intervals[end][1] = newInterval[1]
				}
				rst = append(rst, []int{intervals[begin][0], intervals[end][1]})
				begin = -1
			}
			rst = append(rst, intervals[i])
			continue
		}

		curr := intervals[i]
		if begin == -1 && (curr[0] >= newInterval[0] && curr[0] <= newInterval[1] ||
			curr[1] >= newInterval[0] && curr[1] <= newInterval[1] ||
			newInterval[0] >= curr[0] && newInterval[0] <= curr[1] ||
			newInterval[1] >= curr[0] && newInterval[1] <= curr[1]) {
			begin = i
		}

		if intervals[i][1] <= newInterval[1] {
			end = i
		}
		if intervals[i][0] <= newInterval[1] {
			end = i
		}
	}

	if begin != -1 {
		ever = true
		if intervals[begin][0] > newInterval[0] {
			intervals[begin][0] = newInterval[0]
		}
		if intervals[end][1] < newInterval[1] {
			intervals[end][1] = newInterval[1]
		}
		rst = append(rst, []int{intervals[begin][0], intervals[end][1]})
	}

	if !ever {
		rst = [][]int{}
		var i = 0
		for ; i < len(intervals)-1; i++ {
			rst = append(rst, intervals[i])
			if intervals[i][1] < newInterval[0] && intervals[i+1][0] > newInterval[1] {
				rst = append(rst, newInterval)
			}
		}
		rst = append(rst, intervals[i])
	}

	return rst
}
```
