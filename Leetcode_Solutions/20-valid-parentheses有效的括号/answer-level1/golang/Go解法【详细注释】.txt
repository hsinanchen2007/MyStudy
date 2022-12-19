### 解题思路
维护一个栈，匹配不上的就入栈，匹配上的就出栈，最后看栈是不是空的，空的说明全匹配上了

### 代码

```golang
func isValid(s string) bool {
	// 空字符串默认配对的
	if s == "" {
		return true
	}
	// 奇数个括号肯定不能全匹配
	if len(s)%2 == 1 {
		return false
	}
	// 建立映射关系
	// keyMap["}"] = {
	// keyMap["{"] = 空
	keyMap := map[string]string{
		"}": "{",
		"]": "[",
		")": "(",
	}
	var table []string
	for i := 0; i < len(s); i++ {
		// 如果栈里有元素
		if len(table) > 0 {
			tmp, ok := keyMap[string(s[i])]
			// 如果和map里面的有匹配，也就是，目前元素是右半边括号
			if ok {
				top := table[len(table)-1]
				// 【重要】如果当前遍历到的元素的映射和栈顶上的括号相同
				if top == tmp {
					// 栈顶元素pop掉
					table = table[:len(table)-1]
					// 跳过这次循环
					continue
				}
			} // ↓
		}
		// 空栈或者没匹配上，就加入栈
		table = append(table, string(s[i]))
	}
	// 如果最后栈是空的，说明都匹配上了，返回true
	return len(table) == 0
}

```