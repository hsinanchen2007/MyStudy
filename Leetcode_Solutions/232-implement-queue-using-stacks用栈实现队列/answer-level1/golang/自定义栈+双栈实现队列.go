首先使用切片自定义一个栈：
```go
type Stack struct {
	data []int
	top  int
}

func NewStack() Stack {
	return Stack{
		data: make([]int, 0),
		top:  -1,
	}
}

func (s *Stack) Push(x int) {
	s.data = append(s.data, x)
	s.top++
}

func (s *Stack) Pop() int {
	ret := s.data[s.top]
	s.data = s.data[0:s.top]
	s.top--
	return ret
}

func (s *Stack) Peek() int {
	return s.data[s.top]
}

func (s *Stack) Size() int {
	return len(s.data)
}
```

然后使用两个栈(in、out)来实现队列，其中 in 用于入队操作，out 用于出队操作：

```go
type MyQueue struct {
	in, out stack.Stack
}

func Constructor() MyQueue {
	return MyQueue{
		in:  stack.NewStack(),
		out: stack.NewStack(),
	}
}

func (this *MyQueue) Push(x int) {
	this.in.Push(x)
}

// 出队时，如果 out 栈中元素为 0，需要先将 in 栈中的元素出栈并逐个入栈到 out 中，然后再从 out 中出队
func (this *MyQueue) Pop() int {
	if this.out.Size() == 0 {
        inSize := this.in.Size()
		for i := 0; i < inSize; i++ {
			this.out.Push(this.in.Pop())
		}
	}
	return this.out.Pop()
}

func (this *MyQueue) Peek() int {
	if this.out.Size() == 0 {
        inSize := this.in.Size()
		for i := 0; i < inSize; i++ {
			this.out.Push(this.in.Pop())
		}
	}
	return this.out.Peek()
}

func (this *MyQueue) Empty() bool {
	return this.out.Size() == 0 && this.in.Size() == 0
}
```
