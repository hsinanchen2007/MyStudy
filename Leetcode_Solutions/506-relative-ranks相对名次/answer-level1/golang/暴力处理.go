func findRelativeRanks(nums []int) []string {
	if len(nums) == 0 {return make([]string, 0)}
	arr := make([]string, len(nums))
	for i := 0; i < len(nums); i++ {
		arr1 := make([]int, len(nums))
		copy(arr1, nums)
		sort.Ints(arr1)
		target := convertCompile(arr1, nums[i])
		switch target {
		case "1": arr[i] = "Gold Medal"
		case "2": arr[i] = "Silver Medal"
		case "3": arr[i] = "Bronze Medal"
		default : arr[i] = target
		}

	}
	return arr
}

func convertCompile(nums []int, target int) string{
	for i := 0; i < len(nums); i++ {
		if target == nums[i] {
			return strconv.Itoa(len(nums) - i)
		}
	}

	return ""
}