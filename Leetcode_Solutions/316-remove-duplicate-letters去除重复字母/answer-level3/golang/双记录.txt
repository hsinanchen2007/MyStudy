```
func removeDuplicateLetters(s string) string {
	recode := [26]int{}  // 字符出现次数
	contain := [26]int{} // 字符是否包含在栈中,在栈中为1
	stack := []rune{}
	for _, c := range s {
		// 记录字符出现次数
		recode[c-'a']++
	}
	for _, c := range s {
		// 当栈中已包含c，则直接继续下一个字符
		if contain[c-'a'] == 1 {
			// 减少c字符出现的次数
			recode[c-'a']--
			continue
		}

		/*
			1. 栈大于0
			2. 栈顶字符大于c
			3. 栈顶字符在后续字符中仍出现
		*/
		for len(stack) > 0 && stack[len(stack)-1] > c &&
			recode[stack[len(stack)-1]-'a'] > 0 {

			// 栈中不再含栈顶字符
			contain[stack[len(stack)-1]-'a'] = 0

			// 删除栈顶字符
			stack = stack[:len(stack)-1]
		}

		// 添加新字符
		stack = append(stack, c)
		// 减少c出现次数
		recode[c-'a']--
		// 标记栈中包含c字符
		contain[c-'a'] = 1
	}
	return string(stack)
}
```
