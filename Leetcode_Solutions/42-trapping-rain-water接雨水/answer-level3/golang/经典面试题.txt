### 解题思路
记录当前节点左右两侧最高峰，遍历相加当前节点可存储的雨水即可

### 代码

```golang
func trap(height []int) int {
	if len(height) == 0 {
		return 0
	}
	left, right, temp := make([]int, len(height)), make([]int, len(height)), 0
	for i := range height {
		left[i] = temp
		if height[i] > temp {
			temp = height[i]
		}
	}
	temp = 0
	for i := len(height) - 1; i > -1; i-- {
		right[i] = temp
		if height[i] > temp {
			temp = height[i]
		}
	}
	temp = 0
	for i := range height {
		if left[i] > height[i] && right[i] > height[i] {
			temp += min(left[i], right[i]) - height[i]
		}
	}
	return temp
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

```