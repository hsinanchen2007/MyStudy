### 解题思路
模拟

### 代码

```golang
func validateStackSequences(pushed []int, popped []int) bool {
	stack := make([]int, 0)
	i := 0
	j := 0
	for j < len(popped) {
		for i < len(pushed) {
			stack = append(stack, pushed[i])
			i++
			if stack[len(stack)-1] == popped[j] {
				break
			}
		}
		for len(stack) > 0 && stack[len(stack)-1] == popped[j] {
			stack = stack[:len(stack)-1]
			j++
		}
		if i == len(pushed) {
			break
		}
	}
	return len(stack) == 0
}
```