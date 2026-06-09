```
func pivotIndex(nums []int) int {
	if len(nums) == 1 {
		return 0
	}
	sum := 0
	for _, num := range nums {
		sum += num
	}

	leftMap := make(map[int]int)
	for i := range nums {
		left := 0
		l, ok := leftMap[i-2]
		if ok {
			left = l + nums[i-1]
			leftMap[i-1] = left
		} else {
			if i == 1 {
				leftMap[i-1] = nums[0]
				left = leftMap[i-1]
			}
		}
		if sum-nums[i]-left == left {
			return i
		}
	}

	return -1
}
```