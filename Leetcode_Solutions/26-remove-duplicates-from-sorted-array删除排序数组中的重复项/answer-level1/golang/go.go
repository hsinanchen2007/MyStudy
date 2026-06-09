func removeDuplicates(nums []int) int {
	l := len(nums)
	if l < 1 {
		return 0
	}
	count := 1
	for i := 1; i < l; i++ {
		if nums[i-1] != nums[i] {
			nums[count] = nums[i]
			count += 1
		}
	}
	return count
}