解题思路：
两个队列，一个只负责栈的input功能，另一个只负责栈的output功能。
代码：
```go

// MyStack 是用 Queue 实现的 栈
type MyStack struct {
	a, b *Queue
}

// Constructor Initialize your data structure here.
func Constructor() MyStack {
	return MyStack{a: NewQueue(), b: NewQueue()}
}

// Push Push element x onto stack.
func (this *MyStack) Push(x int) {
	this.a.Push(x)
}

// Pop Removes the element on top of the stack and returns that element.
func (this *MyStack) Pop() int {
	if this.b.Len() == 0 {
		this.a, this.b = this.b, this.a
	}

	for this.b.Len() > 1 {
		this.a.Push(this.b.Pop())
	}
	return this.b.Pop()
}

// Top Get the top element.
func (this *MyStack) Top() int {
	res := this.Pop()
	this.a.Push(res)
	return res
}

// Empty Returns whether the stack is empty.
func (this *MyStack) Empty() bool {
	return this.a.Len() + this.b.Len() == 0
}

// Queue 是用于存放 int 的队列
type Queue struct {
	nums []int
}

// NewQueue 返回 *kit.Queue
func NewQueue() *Queue {
	return &Queue{nums: []int{}}
}

// Push 把 n 放入队列
func (q *Queue) Push(n int) {
	q.nums = append(q.nums, n)
}

// Pop 从 q 中取出最先进入队列的值
func (q *Queue) Pop() int {
	res := q.nums[0]
	q.nums = q.nums[1:]
	return res
}

// Len 返回 q 的长度
func (q *Queue) Len() int {
	return len(q.nums)
}

// IsEmpty 反馈 q 是否为空
func (q *Queue) IsEmpty() bool {
	return q.Len() == 0
}
```

