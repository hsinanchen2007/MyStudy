
![image.png](https://pic.leetcode-cn.com/d419c7653e1b2e2a93cddec120f5ee0220386f303b8483b39913c8b5a5dcb563-image.png)

```
type MyQueue struct {
    Stack []int
}


/** Initialize your data structure here. */
func Constructor() MyQueue {
    return MyQueue{Stack:make([]int,0)}
}


/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
    this.Stack = append(this.Stack, x)
}


/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
    alen := len(this.Stack)
    if alen == 0 {
        return 0
    }
    x := this.Stack[0]
    this.Stack = this.Stack[1:]
    return x
}


/** Get the front element. */
func (this *MyQueue) Peek() int {
    alen := len(this.Stack)
    if alen == 0 {
        return 0
    }
    return this.Stack[0]
}


/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
    if len(this.Stack) == 0 {
        return true
    }
    return false
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
```