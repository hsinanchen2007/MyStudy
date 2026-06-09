```
func maxArea(height []int) int {
	// max := 0
	// for i := 0; i < len(height); i++ {
	// 	for j := 1; j < len(height); j++ {
	// 		info := 0
	// 		if height[i] >= height[j] {
	// 			info = height[j]
	// 		} else {
	// 			info = height[i]
	// 		}

	// 		if info*(j-i) > max {
	// 			max = info * (j - i)
	// 		}
	// 	}
	// }
	max := 0
	i, j := 0, len(height)-1

	for i < j {
		info := 0
		l := j - i
		if height[i] >= height[j] {
			info = height[j]
			j--
		} else {
			info = height[i]
			i++
		}

		if info*l > max {
			max = info * l
		}
	}

	return max
}
```
