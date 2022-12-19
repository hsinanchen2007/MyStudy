func reverse(x int) int {
	var (
		tm = 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10
		add, res = 1, 0
		fg, sign = false, true	
	)
	if x < 0{
		x = -x
		sign = false
	}
	for {
		if tm < 1 {
			break
		}
		if fg {
			head := x / tm
			res += add * head
			x -= head * tm
			add *= 10
			tm /= 10
			continue
		}
		if x/tm > 0 {
			fg = true
		} else {
			tm /= 10
			continue
		}
	}
	if !sign{
		res = -res
	}
	if res > (1<<31)-1 || res < -(1<<31) {
		return 0
	}
	return res
}