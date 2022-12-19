```
func rob(nums []int) int {
    max := 0
	opt := make(map[int]int)
	for i := range nums {
		if i == 0 {
			opt[0] = nums[0]
		} else if i == 1 {
			v0 := nums[0]
			v1 := nums[1]
			if v0 > v1 {
				opt[1] = v0
			} else {
				opt[1] = v1
			}
		} else {
			v0 := nums[i] + opt[i-2]
			v1 := opt[i-1]

			if v0 > v1 {
				opt[i] = v0
			} else {
				opt[i] = v1
			}
		}

		if opt[i] > max {
			max = opt[i]
		}
	}

	return max
}
```
