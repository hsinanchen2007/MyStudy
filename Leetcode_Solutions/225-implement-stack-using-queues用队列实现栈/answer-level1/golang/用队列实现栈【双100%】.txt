### 解题思路

- quque1 队头表示栈顶，queue1中元素始终是入队元素的倒序
- queue2 用来缓冲，始终为空
- 当插入元素时候，先插入 q2 ，再利用队列的特性将 q1 出队到 q2 ，最后 q2 就表示了元素出栈的顺序，交换 q1 和 q2 即可



### 代码

```golang
type MyStack struct {
    queue1 []int
    queue2 []int

}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        queue1: []int{},
        queue2: []int{},
    }
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.queue2 = append(this.queue2, x)
    for len(this.queue1) > 0 {
        this.queue2 = append(this.queue2, this.queue1[0])
        this.queue1 = this.queue1[1:]
    }
    this.queue1, this.queue2 = this.queue2, this.queue1
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    defer func() {
        this.queue1 = this.queue1[1:]
    }()
    return this.queue1[0]
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.queue1[0]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.queue1) == 0
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