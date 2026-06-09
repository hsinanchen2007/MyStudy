### 解题思路
没啥麻烦的，就是用list实现的，也可以用slice，不过一般做题的时候我都会用list来，这样方便一点

### 代码

```golang
import (
    "container/list"
)
type MyStack struct {
    queue *list.List
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack {list.New()}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.queue.PushBack(x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    res := this.queue.Back()
    value := res.Value.(int)
    this.queue.Remove(res)
    return value
}


/** Get the top element. */
func (this *MyStack) Top() int {
    res := this.queue.Back()
    value := res.Value.(int)
    return value
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
   return this.queue.Len() == 0
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