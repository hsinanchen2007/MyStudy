func maxSlidingWindow(nums []int, k int) []int {
    var ret,windows []int
	for i,v:=range nums{
		if i >= k && windows[0] <= i-k{
			windows = windows[1:]
		}
		for  len(windows) > 0 && nums[windows[len(windows)-1:][0]] <= v {
			windows = windows[:len(windows)-1]
		}
		windows = append(windows, i)
		if i >= k-1{
			ret = append(ret, nums[windows[0]])
		}
	}
	return ret
}