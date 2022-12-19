func trap(height []int) int {
	if len(height) == 0 {
		return 0
	}
	var res int
	var leftMax = make([]int, len(height))
	var max = 0
	//init left max arr
	for i := 0; i < len(height)-1; i++ {
		v := height[i]
		if v > max {
			leftMax[i+1] = v
			max = v
		} else {
			leftMax[i+1] = max
		}
	}
	rightMax := height[len(height)-1]
	for i := len(height) - 2; i >= 0; i-- {
		var curMax int
		v := height[i]
		leftMax := leftMax[i]
		//init curMax
		if rightMax > leftMax {
			curMax = leftMax
		} else {
			curMax = rightMax
		}
		//add
		if curMax > v {
			res += (curMax - v)
		}
		//update right max
		if rightMax < v {
			rightMax = v
		}
	}
	return res
}
