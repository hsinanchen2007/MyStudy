### 解题思路
用栈去存储所有左括号，当循环遍历遇到右括号时，从栈顶取出第一个元素，查看是否能和这个右括号匹配，如果不能匹配则一定不是有效的括号。

边界考虑
1. 如果一个左括号都没有，那么 pop 出的元素肯定没有，直接返回 false
2. 如果左括号多了，那么最后的栈顶索引一定大于 0，直接返回 false

### 代码

```golang
type Stack struct {
	top int
	arr []rune
}

func (s *Stack) push(item rune) {
	s.arr[s.top] = item
	s.top++
}

func (s *Stack) pop() (rune, bool) {
	if s.top == 0 {
		return 0, false
	}
	s.top--
	ch := s.arr[s.top]
	return ch, true
}

func isValid(s string) bool {
	st := &Stack{
		top: 0,
		arr: make([]rune, len(s)),
	}

	for _, ch := range s {
		if ch == 40 || ch == 91 || ch == 123 {
			st.push(ch)
		} else {
			item, ok := st.pop()
			if !ok {
				return false
			}
			if item == 40 && ch != 41 || item == 91 && ch != 93 || item == 123 && ch != 125 {
				return false
			}
		}
	}

	return st.top == 0
}

```