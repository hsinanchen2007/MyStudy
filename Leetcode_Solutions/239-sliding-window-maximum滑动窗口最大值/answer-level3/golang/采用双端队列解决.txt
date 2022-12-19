```
//方法1：维护k个大顶堆的heap 方法2：采用一个双端队列
func maxSlidingWindow(nums []int, k int) []int {
	window, res := []int{}, []int{}
	if len(nums) == 0 {
		return res
	}
	for i, v := range nums {
		if i > k && i - k >= window[0] {	//如果window[0]不在窗口中了，那么移除window[0]
			window = window[1:]
		}
		for len(window) > 0 && nums[window[len(window)-1]] <= v {	//比较新进入window的值和pre value的大小，如果pre value的值小，去掉
			window = window[:len(window)-1]
		}
		window = append(window, i)	//新的值进入Window
		if i >= k-1 {
			res = append(res, nums[window[0]])
		}
	}
	return res
}
```
