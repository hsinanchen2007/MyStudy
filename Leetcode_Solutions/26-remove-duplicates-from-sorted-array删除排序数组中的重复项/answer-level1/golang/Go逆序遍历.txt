逆序遍历数组，将重复数值排除并重组数组切片。
```go []
func removeDuplicates(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	for i := len(nums) - 2; i >= 0; i-- {
		if nums[i] == nums[i+1] {
			nums = append(nums[0:i], nums[i+1:]...)
		}
	}
	return len(nums)
}