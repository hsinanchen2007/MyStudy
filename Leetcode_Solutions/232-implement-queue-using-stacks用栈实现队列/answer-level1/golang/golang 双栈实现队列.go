解题思路：
一个栈负责input，另一个负责output。
代码：
```go
type MyQueue struct {
	a,b *Stack
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{a: NewStack(), b: NewStack()}
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
	this.a.Push(x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	if this.b.Len() > 0 {
		return this.b.Pop()
	}
	for this.a.Len() > 0 {
		this.b.Push(this.a.Pop())
	}
	return this.b.Pop()
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	res := this.Pop()
	this.b.Push(res)
	return res
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return this.a.Len() + this.b.Len() == 0
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */



// Stack 是用于存放 int 的 栈
type Stack struct {
	nums []int
}

// NewStack 返回 *kit.Stack
func NewStack() *Stack {
	return &Stack{nums: []int{}}
}

// Push 把 n 放入 栈
func (s *Stack) Push(n int) {
	s.nums = append(s.nums, n)
}

// Pop 从 s 中取出最后放入 栈 的值
func (s *Stack) Pop() int {
	res := s.nums[len(s.nums)-1]
	s.nums = s.nums[:len(s.nums)-1]
	return res
}

// Len 返回 s 的长度
func (s *Stack) Len() int {
	return len(s.nums)
}

// IsEmpty 反馈 s 是否为空
func (s *Stack) IsEmpty() bool {
	return s.Len() == 0
}
```
