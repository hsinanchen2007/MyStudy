### 解题思路
此处撰写解题思路

### 代码

```golang
func trap(height []int) int {
	l := len(height)
	if l < 2 {
		return 0
	}
	// 栈 保存当前最小的条形的下标
	var stack []int
	// 结果接水量
	var res = 0
	// 当前游标
	for curr := 0;curr < l; curr++ {
		for len(stack) > 0 && height[curr] > height[stack[len(stack) - 1]] {
			// 栈顶元素
			top := stack[len(stack) - 1]
			// 出栈
			stack = stack[:len(stack) - 1]
			if len(stack) == 0 {
				break
			}
			// 距离
			distance := curr - stack[len(stack) - 1] - 1
			// 水量只差，用最小的柱减去去掉的
			water := min(height[curr], height[stack[len(stack) - 1]]) - height[top]
			res = res + distance * water
		}
		// 入栈
		stack = append(stack, curr)
	}
	return res
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

```