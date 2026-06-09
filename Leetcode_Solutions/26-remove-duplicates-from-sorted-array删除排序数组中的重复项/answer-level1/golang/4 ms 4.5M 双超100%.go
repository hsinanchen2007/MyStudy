```

func removeDuplicates(nums []int) int {

	location := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1] {
			continue
		}
		nums[location] = nums[i]
		location++
	}
	return location
}

```