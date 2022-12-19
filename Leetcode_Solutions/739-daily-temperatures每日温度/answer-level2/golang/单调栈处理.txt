
```
// 使用单调栈，栈顶存的是温度低的待处理的T元素索引
func dailyTemperatures(T []int) []int {
	ss := &stack{}
	ss.data = []int{}

	res := make([]int, len(T))

	for i := 0; i < len(T); i++ {

		if ss.Empty() || T[i] < T[ss.Top()] {
			ss.Push(i)
		} else {
			for ss.Empty() == false && T[i] > T[ss.Top()] {
				res[ss.Top()] = i - ss.Top()
				ss.Pop()
			}
			ss.Push(i)
		}
	}
	return res

}

type stack struct {
	data []int
}

func (s *stack) Pop() {
	l := len(s.data)
	if l > 0 {
		s.data = append(s.data[:l-1], s.data[l:]...)
	}
}

func (s *stack) Push(a int) {
	s.data = append(s.data, a)
}

func (s *stack) Empty() bool {
	if len(s.data) == 0 {
		return true
	}
	return false
}

func (s *stack) Top() int {
	return s.data[len(s.data)-1]
}
```