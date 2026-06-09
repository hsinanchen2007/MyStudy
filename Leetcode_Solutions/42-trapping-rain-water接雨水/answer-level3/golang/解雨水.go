### 解题思路
此处撰写解题思路

### 代码

```golang
func trap(height []int) int {
    result := 0
	// 特殊情况处理
	if len(height) <= 2 {
		return result
	}
	l := len(height)
	maxLeft := 0
	maxRight := 0
	left, right := 1, l-2
	for i := 1; i < l-1; i++ {
		if height[left-1] < height[right+1] {
			maxLeft = max(maxLeft, height[left-1])
			if height[left] < maxLeft {
				result += maxLeft - height[left]
			}
			left++
		} else {
			maxRight = max(maxRight, height[right+1])
			if height[right] < maxRight {
				result += maxRight - height[right]
			}
			right--
		}
	}
	return result
}
func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

```