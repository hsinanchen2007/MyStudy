func reverse(x int) int {
	ret := 0
	for x !=0 {
		mod := x % 10
		x = x / 10
		ret = ret * 10 + mod
		if ret > intsets.MaxInt {
			ret = 0
		}
		if ret < intsets.MinInt {
			ret = 0
		}
	}
	return ret
}