### 解题思路
使用数组实现

### 代码

```golang
type MyStack struct {
    Val []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{Val:make([]int,0)}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.Val = append(this.Val, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    res := this.Val[len(this.Val)-1]
    this.Val = this.Val[:len(this.Val)-1]
    return res
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.Val[len(this.Val)-1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.Val) == 0
}

/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */
```

### 解题思路
使用队列实现

### 代码

```golang
// MyStack是利用Queue实现的栈
type MyStack struct {
   a, b *Queue
}


/** Initialize your data structure here. */
func Constructor() MyStack {
   return MyStack{a: NewQueue(), b: NewQueue()}
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
   return (this.a.Len() + this.b.Len()) == 0
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */

// Queue 是用于存放int的队列
type Queue struct {
   nums []int
}

// NewQueue 返回 *kit.Queue
func NewQueue() *Queue {
   return &Queue{nums: []int{}}
}

// Push 把n放入队列
func (q *Queue) Push(n int) {
   q.nums = append(q.nums, n)
}

// Pop 从q中取出最先进入队列的值
func (q *Queue) Pop() int {
   res := q.nums[0]
   q.nums = q.nums[1:]
   return res
}

// Len 返回q的长度
func (q *Queue) Len() int {
   return len(q.nums)
}

// IsEmpty 反馈q是否为空
func (q *Queue) IsEmpty() bool {
   return q.Len() == 0
}
```