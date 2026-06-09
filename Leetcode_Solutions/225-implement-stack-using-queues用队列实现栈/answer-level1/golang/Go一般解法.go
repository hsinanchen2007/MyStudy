### 解题思路

关键性质：队列反序可以当做栈，而每次入队前将队内元素后置就可以做到这种反序。

### 代码

```golang
import "container/list"

type MyStack struct {
    q   *list.List
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{q: list.New()}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.q.PushBack(x)
    for i := this.q.Len(); i > 1; i-- {
        this.q.PushBack(this.q.Remove(this.q.Front()))
    }
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    return this.q.Remove(this.q.Front()).(int)
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.q.Front().Value.(int)
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    if this.q.Len() <= 0 { return true } else { return false }
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