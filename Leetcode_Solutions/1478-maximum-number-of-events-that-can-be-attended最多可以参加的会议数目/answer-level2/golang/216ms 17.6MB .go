### 解题思路
此处撰写解题思路

### 代码

```golang
func maxEvents(events [][]int) int {

	eLen := len(events)
	if eLen <= 1 {
		return eLen
	}

	// minDay := events[0][0]
	sort.Slice(events, func(i int, j int) bool {
		// if events[i][0] < minDay {
		// 	minDay = events[i][0]
		// }
		// if events[j][0] < minDay {
		// 	minDay = events[j][0]
		// }
		return events[i][1] < events[j][1]
	})
	// fmt.Println(minDay)
	maxDay := events[eLen-1][1]

	days := make([]bool, maxDay+1)
	maxEvent := 0
	for i := 0; i < eLen; i++ {
		for j := events[i][0]; j <= events[i][1]; j++ {
			if !days[j] { //每个会议只占用一天
				days[j] = true
				maxEvent++
				break
			}
		}
	}

	return maxEvent

}
```