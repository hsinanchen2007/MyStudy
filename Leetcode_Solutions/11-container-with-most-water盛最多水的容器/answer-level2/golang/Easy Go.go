```
func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}

func maxArea(height []int) int {
	max := 0
	i := 0
	j := len(height) - 1

	for i < j {
		temp := (j - i) * min(height[i], height[j])
		if temp > max {
			max = temp
		}

		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}

	return max
}
```
