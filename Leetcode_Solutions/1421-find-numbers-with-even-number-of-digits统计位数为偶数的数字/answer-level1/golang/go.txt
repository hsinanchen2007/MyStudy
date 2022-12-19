func findNumbers(nums []int) int {
	res := 0
	for _, j := range nums {
		m := strconv.Itoa(j)
		if len(m)%2 == 0 {
			res++
		}
	}
	return res
}