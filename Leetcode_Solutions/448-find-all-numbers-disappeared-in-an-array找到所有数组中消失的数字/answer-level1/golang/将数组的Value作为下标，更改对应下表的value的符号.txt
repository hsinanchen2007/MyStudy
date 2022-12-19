func findDisappearedNumbers(nums []int) []int {
	result := make([]int,0,0)
	for _, value := range nums{
		if value < 0{
			value = -value
		}
		if nums[value - 1] > 0 {
			nums[value - 1] = -nums[value - 1]
		}
	}
	for index,value := range nums{
		if value > 0{
			result = append(result, index + 1)
		}
	}
	return result
}