```go
/**
用 队列 实现 栈
*/
type MyStack struct {
    a *Queue
    b *Queue
}

/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{a:NewQueue(), b:NewQueue()}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    if this.a.Len() == 0 {
        this.a, this.b = this.b, this.a
    }
    this.a.Push(x)
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    if this.a.Len() == 0 {
        this.a, this.b = this.b, this.a
    }
    for this.a.Len() > 1 {
        this.b.Push(this.a.Pop())
    }
    return this.a.Pop()
}

/** Get the top element. */
func (this *MyStack) Top() int {
    res := this.Pop()
    this.Push(res)
    return res
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    if this.a.Len() + this.b.Len() == 0 {
        return true
    }
    return false
}

/**
队列相关实现
*/

// 用于存放 int 的队列
type Queue struct {
    nums []int
}

// 创建一个队列
func NewQueue() *Queue {
    return &Queue{nums:[]int{}}
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