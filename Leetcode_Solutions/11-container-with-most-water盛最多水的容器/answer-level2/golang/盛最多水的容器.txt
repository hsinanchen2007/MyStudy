
```Go
// 双指针 - 单向移动
func maxArea(height []int) int {
	start, end, val, max := 0, len(height) - 1, 0, 0
	for !(start == end) {
		if height[start] < height[end] {
			val = height[start] * (end - start)
			start++
		} else {
			val = height[end] * (end - start)
			end--
		}
		if val > max { max = val }
	}

	return max
}
```
