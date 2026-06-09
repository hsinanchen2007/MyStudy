```
func findMin(nums []int) int {
	var (
		i      int
		length = len(nums)
	)

	for i = 0; i < length-1; i++ {
		if nums[i+1] < nums[i] {
			return nums[i+1]
		}
	}
	return nums[0]
}
```
