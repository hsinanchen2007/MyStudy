简单思路：
1. 根据开始时间和结束时间排序
2. 判断当前是否有已经结束的房间，有的话就替换


```
func minMeetingRooms(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[j][0] {
			return intervals[i][1] < intervals[j][1]
		}
		return intervals[i][0] < intervals[j][0]
	})
	m := make(map[[2]int]int)
	ret := 0
	for i := 0; i < len(intervals); i++ {
		for k := range m {
			if k[1] <= intervals[i][0] {
				m[k]--
				ret--
				if m[k] == 0 {
					delete(m, k)
				}
				break
			}
		}
		m[[2]int{intervals[i][0], intervals[i][1]}]++
		ret++
	}
	return ret
}
```
