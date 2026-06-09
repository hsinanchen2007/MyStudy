## 思路
使用栈, golang没有就自己做！ 
先将`{} [] ()`放到map，一会用来判断是否存在于map用。
遍历这个字符串，如果`stack`为空的就把当前字符串放进`stack`，不为空就取出`stack`尾元素，与当前遍历的字符串`i`进行拼接，判断是否存在于`map`中，存在就删除这个`stack`元素，不存在就将`i`也放入`stack`中. 

最后如果`stack`为空 就证明这个字符串的括号是有效的.


```go
func isValid(s string) bool {
	stack := make([]string, 0)
	tep := map[string]bool{"{}": true, "[]": true, "()": true}
	for _, i := range s {
		if len(stack) == 0 {
			stack = append(stack, string(i))
		} else if _, ok := tep[stack[len(stack)-1]+string(i)]; ok {
			stack = stack[:len(stack)-1]

		} else {
			stack = append(stack, string(i))
		}

	}

	return len(stack) == 0
}
```
