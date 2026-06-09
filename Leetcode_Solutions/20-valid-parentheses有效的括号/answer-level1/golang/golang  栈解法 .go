解题思路：
   1，用map存储括号对应关系, 注意是以右括号为Key  map{ "}":"{", "]":"[", ")":"("}
   2，遍历字符串，
   3，碰到 "[", "{", "(" 左括号入栈
   4，碰到 "]", "}", ")" 右括号出栈，判断出栈元素是否匹配对应关系，
      匹配成功继续遍历，匹配错误直接return；如果一开始就碰到右括号，
      栈为空，直接return
   5, 最后看栈是否为空，空表示全部匹配，不为空表示括号有问题
   
ps: golang 居然没有内置栈数据结构，只能自己手写了

type stack struct {
	list []string
	top  int
}

// 初始化
func (s *stack) initStack(size int) {
	s.list = make([]string, size)
	s.top = -1
}

// 入栈
func (s *stack) insert(value string) {
	s.top++
	s.list[s.top] = value
}

// 出栈
func (s *stack) pop() (res string) {
	if s.isEmpty() {
		res = "empty"
		return
	}
	res = s.list[s.top]
	s.top--
	return
}

// 判断是否为空
func (s *stack) isEmpty() (res bool) {
	if s.top == -1 {
		res = true
	} else {
		res = false
	}
	return
}

func isValid(s string) bool {
		relation := make(map[string]string)
		relation["}"] = "{"
		relation[")"] = "("
		relation["]"] = "["

		stackS := &stack{}
		stackS.initStack(len(s))
		result := false

		for _, value := range s {
			if v, ok := relation[string(value)]; ok {
				// 存在即代表右括号，出栈
				popValue := stackS.pop()
				if popValue == "empty" {
					return false
				}
				if popValue != v {
					return false
				}
			} else {
				// 不存在即代表左括号，入栈
				stackS.insert(string(value))
			}
		}

		if stackS.isEmpty() {
			result = true
		}
		return result
}
