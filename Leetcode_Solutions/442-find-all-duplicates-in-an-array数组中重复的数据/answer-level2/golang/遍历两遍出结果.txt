func findDuplicates(nums []int) []int {
	n := len(nums)
	for _, v := range nums {
		for v > n {
			v -= n
		}
		nums[v-1] += n
	}
	ret := []int{}
	for i, v := range nums {
		if v > 2*n && v <= 3*n {
			ret = append(ret, i+1)
		}
	}
	return ret
}
