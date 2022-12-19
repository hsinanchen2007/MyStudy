```
 func lastStoneWeight(stones []int) int {
	// 每次取最大两个，有不等放到数组中
	for len(stones) >= 2 {
		// 正序排序
		sort.Ints(stones)
		stoneLen := len(stones)
		stoneDiff := 0
		// 比较差值
		if stones[stoneLen-1] > stones[stoneLen-2] {
			stoneDiff = stones[stoneLen-1] - stones[stoneLen-2]
		}
		// 删除最大两个
		stones = stones[0 : stoneLen-2]
		// 有差值，放到数组
		if stoneDiff > 0 {
			stones = append(stones, stoneDiff)
		}
	}
	if len(stones) > 0 {
		// 数组不为空返回第一个
		return stones[0]
	} else {
		// 数组为空返回0
		return 0
	}
}
```
