```
func removeDuplicates(nums []int) int {
    if len(nums) == 0 {
		return 0
	}

	result := 1
	cur := nums[0]

	for i := 1; i < len(nums); i++ {
		if cur != nums[i] {
			cur = nums[i]
			nums[result] = cur
			result++
		}

	}
    
	return result
}
```