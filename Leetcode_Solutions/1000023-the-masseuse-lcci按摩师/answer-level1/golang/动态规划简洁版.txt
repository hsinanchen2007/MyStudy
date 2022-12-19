```go
func massage(nums []int) int {
    if len(nums) == 0 {
		return 0
	}

	if len(nums) == 1 {
		return nums[0]
	}

	max := func(i, j int) int {
		if i > j {
			return i
		}
		return j
	}

	var pre, cur, temp int
	for _, num := range nums {
		temp = cur
		cur = max(pre+num, cur)
		pre = temp
	}

	return cur
}
```