### 解题思路


### 代码

```golang
type Stack struct {
	data []int
}

func (s *Stack) IsEmpty() bool {
	return len(s.data) == 0
}

func (s *Stack) Push(i int) {
	s.data = append(s.data, i)
}

func (s *Stack) Pop() (int, error) {
	if s.IsEmpty() {
		return 0, errors.New("empty stack")
	}
	tail := len(s.data) - 1
	peek := s.data[tail]
	s.data = s.data[:tail]
	return peek, nil
}


func evalRPN(tokens []string) int {
	stack := &Stack{}
	for _, s := range tokens {
		switch s {
		case "+":
			r, _ := stack.Pop()
			l, _ := stack.Pop()
			stack.Push(l + r)

		case "-":
			r, _ := stack.Pop()
			l, _ := stack.Pop()
			stack.Push(l - r)

		case "*":
			r, _ := stack.Pop()
			l, _ := stack.Pop()
			stack.Push(l * r)

		case "/":
			r, _ := stack.Pop()
			l, _ := stack.Pop()
			stack.Push(l / r)

		default:
			i, _ := strconv.Atoi(s)
			stack.Push(i)
		}
	}
	r, _ := stack.Pop()
	return r
}

```