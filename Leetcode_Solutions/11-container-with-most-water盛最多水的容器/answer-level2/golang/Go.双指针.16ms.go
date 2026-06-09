**核心是官方题解提到的，两线段之间形成的区域总是会受到其中较短那条长度的限制。此外，两线段距离越远，得到的面积就越大。
所以从两面逐渐减小（首先移动更短的一边），然后记录最大的面积。**



```
func maxArea(height []int) int {
	size, l, r := 0, 0, len(height)-1

	for l < r {
		s := min(height[l], height[r]) * (r - l)
		if size < s {
			size = s
		}
		if height[l] > height[r] {
			r--
		} else {
			l++
		}
	}

	return size
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
```
