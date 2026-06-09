### 解题思路
采用栈这种数据结构。可以使用标准库提供的双向链表list，也可以使用切片来模拟栈。这里采用第二种方式，因为这样能节省0.1MB内存。
1、先对测试用例整体遍历一次
2、再对用例中每一个对象进行判断，如果是左括号，则入栈。如果是右括号，还要判断该对象是否和栈顶元素匹配，若匹配，则让栈顶元素出栈，若不匹配或者栈中根本没有元素则直接让函数返回false
3、遍历完成后还要判断一下栈内是否仍有元素，若有，说明栈内仍有未匹配成功的括号，返回false。若栈内没有元素，说明所有括号匹配成功，返回true。可直接简写为：return len(stack) == 0
### 代码

```golang
func match(s string) string {
	var res string
	switch s {
	case ")":
		res = "("
	case "]":
		res = "["
	case "}":
		res = "{"
	}
	return res
}
func isValid(s string) bool {
	stack := make([]string, 0)
	for _, v := range s {
		switch string(v) {
		case "(", "[", "{":
			stack = append(stack, string(v))
		case ")", "]", "}":
			if len(stack) != 0 && stack[len(stack)-1] == match(string(v)) {
				stack = stack[:len(stack)-1]
			} else {
				return false
			}
		}
	}
	return len(stack) == 0
}
```