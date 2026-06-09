1. 使用map存储每一分钟的会议占用
2. 按照时间排序
3. 检测最小能力
![image.png](https://pic.leetcode-cn.com/c72ba47c94220b2a60443878d8d1dea1959b10b8b18394cee1935069f55454cc-image.png)

```
func minMeetingRooms(intervals [][]int) int {
	meetingRooms := make(map[int]int)
	for _, interval := range intervals {
		meetingRooms[interval[0]] += 1
		meetingRooms[interval[1]] -=1
	}

	times := make([]int, 0)
	for k := range meetingRooms {
		times = append(times, k)
	}
	sort.Ints(times)

	minRooms := 0
	currentRooms := 0
	for _, time := range times {
		currentRooms += meetingRooms[time]
		minRooms = int(math.Max(float64(minRooms), float64(currentRooms)))
	}
	return minRooms
}
```
