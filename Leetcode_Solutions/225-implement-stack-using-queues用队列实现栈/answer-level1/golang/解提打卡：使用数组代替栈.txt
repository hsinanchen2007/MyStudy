### 解题思路
解题打卡，把数组当成栈使用

### 代码

```golang
type MyStack struct {
    stack []int
    top   int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    var stack MyStack
    stack.top = 0
    return stack
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.stack = append(this.stack, x)
    this.top += 1
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    value := this.stack[this.top-1]
    this.stack = this.stack[:this.top-1]
    this.top -= 1
    return value
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.stack[this.top-1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    if this.top>0 {
        return false
    } else {
        return true
    }
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