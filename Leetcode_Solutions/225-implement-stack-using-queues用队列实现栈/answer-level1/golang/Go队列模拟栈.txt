### 解题思路
用slice来模拟队列操作，那么要用一个队列模拟栈，只需要在入栈的时候，将队列中已有的元素从队列中取出，然后重新入队，这样新入队的元素就位于队列前端了。

### 代码

```golang
type MyStack struct {
    queue []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.queue = append(this.queue, x)
    l := len(this.queue)
    if l > 1{
        this.queue = append(this.queue, this.queue[0: len(this.queue)-1]...)
        this.queue = this.queue[l-1:]
    }
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    first := this.queue[0]
    this.queue = this.queue[1:]
    return first
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.queue[0]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.queue) == 0
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