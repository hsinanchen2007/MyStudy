执行耗时 0ms，内存使用 2.5M
```
func longestCommonPrefix(strs []string) string {

	if len(strs) < 1 {
		return ""
	} else if len(strs) == 1 {
		return strs[0]
	}

	global := ""
	stack := []string{}
	minLength := strs[0]
	min := 0

	// 找出最短元素
	for i := range strs {
		if len(minLength) > len(strs[i]) {
			minLength = strs[i]
			min = i
		}
	}
	strs = append(strs[:min], strs[min+1:]...)

	// 入队列
	for _,v := range minLength {
		stack = append(stack, string(v))
	}

	for index,value := range stack {
		ok := 0
		for _,v := range strs {
			if value == string(v[index]) {
				ok++
			}
		}
		if ok == len(strs) {
			if len(stack) >= 1 {
				global += stack[0]
				stack = stack[1:]
			} else {
				break
			}
		} else {
			break
		}
	}

	if global != "" {
		return global
	} else {
		return "无"
	}
}
```
