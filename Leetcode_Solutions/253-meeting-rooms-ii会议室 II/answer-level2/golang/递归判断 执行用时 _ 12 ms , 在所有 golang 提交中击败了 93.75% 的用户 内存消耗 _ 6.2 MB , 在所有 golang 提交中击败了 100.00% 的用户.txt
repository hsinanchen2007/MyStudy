func minMeetingRooms(intervals [][]int) int {
	if len(intervals) == 0 {
		return 0
	}
	if len(intervals) == 1 {
		return 1
	}

	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] < intervals[j][0] {
			return true
		} else if intervals[i][0] == intervals[j][0] {
			if intervals[i][1] > intervals[j][1] {
				return true
			}
		}
		return false
	})

	num := getNums(intervals)

	return num
}

func getNums(intervals [][]int) int {
	num := 0
	if len(intervals) == 0 {
		return num
	}
	if len(intervals) == 1 {
		return 1
	}

	end := intervals[0][1]
	index := make([]int, 0)
	newIntervals := make([][]int, 0)
	for i := 1; i < len(intervals); i++ {
		if intervals[i][0] >= end {
			index = append(index, i)
			end = intervals[i][1]
		} else {
			newIntervals = append(newIntervals, intervals[i])
		}
	}
	num += 1
	if len(newIntervals) == 0 {
		return num
	}
	num += getNums(newIntervals)
	return num
}
