### 解题思路
单调递减栈

### 代码

```golang
func min(x, y int) int {
	if x > y {
		return y
	}else {
		return x
	}
}
func mctFromLeafValues(arr []int) int {
	ans := 0
	stack := make([]int, 0)
	stack = append(stack, math.MaxInt32)
	for _, v := range arr {
		for len(stack) > 0 && v > stack[len(stack)-1] {
			ans += stack[len(stack)-1] * min(v, stack[len(stack)-2])
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, v)
	}
	for len(stack) > 2 {
		ans += stack[len(stack)-1] * stack[len(stack)-2]
		stack = stack[:len(stack)-1]
	}
	return ans
}
```