### 解题思路
此处撰写解题思路

### 代码

```golang
func trap(height []int) int {
	if height == nil {
		return 0
	}

	var left, right, leftMax, rightMax, res int
	left = 0
	right = len(height)-1

	for left < right {
		if height[left] < height[right] {
			//if height[left] < leftMax {
			if height[left] >= leftMax {
				leftMax = height[left]
			} else {
				res += leftMax - height[left]
			}
			left++
		} else {
			if height[right] > rightMax {
				rightMax = height[right]
			} else {
				res += rightMax - height[right]
			}
			right--
		}

	}
	return res
}
```