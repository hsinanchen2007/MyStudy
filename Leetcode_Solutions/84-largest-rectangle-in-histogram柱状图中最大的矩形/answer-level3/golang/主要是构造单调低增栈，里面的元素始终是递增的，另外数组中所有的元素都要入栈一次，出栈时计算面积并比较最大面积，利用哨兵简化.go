### 解题思路
此处撰写解题思路

### 代码

```golang
func largestRectangleArea(heights []int) int {

	if len(heights) == 0 {
		return 0
	}
	if len(heights) == 1 {
		return heights[0]
	}
	size := len(heights)
	stack := make([]int, 0, size)

	heights = append(heights, 0)
	stack = append(stack, -1) // 添加哨兵
	i := 0
	res := 0

	for i < size+1 && len(stack) != 0 {
		cur := heights[i]
		topindex := stack[len(stack)-1]
		if topindex < 0||cur >= heights[topindex] { // 构造递增栈
			// 入栈
			stack = append(stack, i)
			i++
			continue
		}

		stack = stack[:len(stack)-1]
		// 栈中弹出高的元素之后的值
		begin := stack[len(stack)-1]

		area := (i - begin - 1) * heights[topindex]
		res = max(res, area)
	}
	return res
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

```