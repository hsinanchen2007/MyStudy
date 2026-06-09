提供一种很容易想到的思路
核心思想还是缺失值不超过len或者是len+1
申请一个与原数组等长的数组，遍历然后记下每个在范围内（0~len）出现的数的次数，然后审查该数组中
是否含有值为0即可。
func firstMissingPositive(nums []int) int {
	maxVal := len(nums)
	if maxVal == 0 {
		return 1
	}
	if nums[0] == 1 && maxVal == 1 {
		return 2
	}
	fmt.Println(maxVal)
	countSort := make([]int, maxVal+1)
	for n, _ := range nums {
		if nums[n] <= 0 || nums[n] > maxVal {
			continue
		}
		countSort[nums[n]]++
	}
	var i int
	for i = 1; i <= maxVal; i++ {
		if countSort[i] == 0 {
			return i
		}
	}
	return i
}

