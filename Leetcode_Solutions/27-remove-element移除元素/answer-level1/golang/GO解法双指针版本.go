func removeElement(nums []int, val int) int {
	if len(nums) == 0 {
		return 0
	}

	i, j := 0, len(nums)-1
	for j >= i {
		if nums[j] == val {
			j--
			continue
		}

		if nums[i] == val {
			nums[i] = nums[j]
			j--
		}
		i++
	}

	return j + 1
}