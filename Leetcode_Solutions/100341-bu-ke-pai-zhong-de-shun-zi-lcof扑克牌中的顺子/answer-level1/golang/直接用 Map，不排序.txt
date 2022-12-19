```
func isStraight(nums []int) bool {
	var (
		i, begin int
		numMap   = map[int]int{}
	)
	for i = 0; i < len(nums); i++ {
		numMap[nums[i]]++
		if nums[i] != 0 && numMap[nums[i]] > 1 {
			return false
		}
	}

	for i = 1; i < 14; i++ {
		if numMap[i] != 0 {
			begin = i
		}
		if begin != 0 {
			for i = begin + 1; i < begin+5; i++ {
				if numMap[i] != 1 {
					if numMap[0] == 0 {
						return false
					}
					numMap[0]--
				}
			}
			return true
		}
	}
	return false
}
```
