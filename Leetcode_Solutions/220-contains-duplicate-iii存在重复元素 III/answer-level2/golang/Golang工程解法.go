工程解法。
滑动窗口没毛病。
直接使用map存储就行。
在map存储亮不大时，遍历map。
其余情况，遍历map中的[-k, k]。

``` go
func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
	windowSize := k + 1
	if windowSize > len(nums) {
		windowSize = len(nums)
	}

	// Init
	maps := make(map[int]int)
	for i := 0; i < windowSize; i++ {
		result, tempMap := buildMaps(maps, t, nums[i], nil)
		maps = tempMap
		if result {
			return true
		}
	}

	// Loop
	for i := windowSize; i < len(nums); i++ {
		result, tempMap := buildMaps(maps, t, nums[i], &nums[i - windowSize])
		maps = tempMap
		if result {
			return true
		}
	}

	return false
}

func buildMaps(maps map[int]int, t int, addNum int, deleteNum * int) (bool, map[int]int) {
	if deleteNum != nil {
		delete(maps, *deleteNum)
	}

	if contains(maps, t, addNum) {
		return true, maps
	} else {
		maps[addNum] = 1
		return false, maps
	}
}

func contains(maps map[int]int, t int, addNum int) bool {
	if len(maps) < 10 {
		for key := range maps {
			if key >= addNum - t && key <= addNum + t {
				return true
			}
		}

		return false
	} else {
		for i := addNum - t; i <= addNum + t;i ++ {
			if _, exist := maps[i]; exist {
				return true
			}
		}

		return false
	}
}
```
