### 解题思路
看到这种题目，第一反应就是用栈来解决。
这里如不使用map，多写几个case，会更省内存，就是代码会更冗余。

执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
内存消耗 :2.1 MB, 在所有 Go 提交中击败了30.16%的用户

### 代码

```golang
func isValid(s string) bool {
    var MapBrackets = map[string]string{"}": "{", "]": "[", ")": "("}
	var stack []string // 用一个栈来存放字符
	for i := 0; i < len(s); i++ {
		c := s[i : i+1]
		switch c {
		case "{", "[", "(":
			stack = append(stack, c) // 左括号压入栈中
		case "}", "]", ")":
			if len(stack) == 0 {
				return false // 栈中无左括号，直接返回false
			}
			// 判断栈顶出元素是否为匹配的左括号
			if pop := stack[len(stack)-1]; pop == MapBrackets[c] {
				stack = stack[:len(stack)-1] // 匹配则从栈中弹出左括号继续往后遍历
			} else {
				return false // 不匹配则返回false
			}
		} //括号以外的元素忽略
	}
	return len(stack) == 0 //若栈中还有多余的左括号，则返回false
}

```