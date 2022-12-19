1. 使用map存储每一站的客流数
2. 按照站排序
3. 检测能力是否超限

```
func carPooling(trips [][]int, capacity int) bool {
	passengers := make(map[int]int)
	for _, trip := range trips {
		count := trip[0]
		up := trip[1]
		down := trip[2]
		passengers[down] -= count
		passengers[up] += count
	}

	stations := make([]int, 0)
	for k := range passengers {
		stations = append(stations, k)
	}
	sort.Ints(stations)

	current := 0
	for _, station := range stations {
		current += passengers[station]
		if current > capacity {
			return false
		}
	}
	return true
}
```
