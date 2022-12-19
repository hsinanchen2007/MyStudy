### 解题思路
此处撰写解题思路

### 代码

```golang
func removeKdigits(num string, k int) string {
	l := len(num)
	value := make([]int, l)
	for k, v := range num {
		value[k] = int(v - '0')
	}
	stack := make([]int, 0)
	for i := 0; i < len(value); i++ {
		// pop
		for len(stack)> 0 && stack[len(stack)-1] > value[i] && k > 0 {
			k--
			// pop
			stack = stack[:len(stack)-1]
		}
		// push
		if !(value[i] == 0 && len(stack) == 0) {
			stack = append(stack, value[i])
		}
	}
	for len(stack) > 0 && k > 0 {
		// 删除多余的元素
		stack = stack[:len(stack)-1]
		k--
	}
	result := make([]byte, len(stack))
	for k, v := range stack {
		result[k] = byte(v + '0')
	}
	if string(result) == "" {
		return "0"
	}
	return string(result)
}

```