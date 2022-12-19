### 解题思路
此处撰写解题思路

### 代码

```golang
// 按列求
func trap(height []int) int {
	sum := 0
	length := len(height)

	for i := 1; i < length-1; i++ {
		leftmax := 0
		rightmax := 0
		for j := i - 1; j >= 0; j-- {
			if height[j] > leftmax {
				leftmax = height[j]
			}
		}
		for j := i + 1; j <= length-1; j++ {
			if height[j] > rightmax {
				rightmax = height[j]
			}

		}
		max := min(leftmax, rightmax)
		if height[i] < max {
			sum += max - height[i]
		}
	}
	return sum
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

```