### 解题思路
使用单调递增栈存储下标, 然后逆序遍历

### 代码

```golang
func dailyTemperatures(T []int) []int {
	stack := make([]int, 0, len(T))
	result := make([]int, len(T))
	for i := len(T) - 1; i >= 0; i-- {
		for len(stack) > 0 && T[i] >= T[stack[len(stack)-1]] {
			stack = stack[:len(stack)-1]
		}
		if len(stack) > 0 {
			result[i] = stack[len(stack)-1] - i
		}
		stack = append(stack, i)
	}
	return result
}
```