### 解题思路
使用辅助栈用于返回最小值

### 代码

```golang
type MinStack struct {
    stack []int
    minStack []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
    var stack MinStack
    const INT_MAX = int(^uint(0) >> 1)
    stack.minStack = append(stack.minStack, INT_MAX) //初始化最小值栈
    return stack
}


func (this *MinStack) Push(x int)  {
    this.stack = append(this.stack, x)
    if this.minStack[len(this.minStack)-1] >= x {
        this.minStack = append(this.minStack, x)
    }
}


func (this *MinStack) Pop()  {
    if this.minStack[len(this.minStack)-1] == this.stack[len(this.stack)-1]{
        this.minStack = this.minStack[0:len(this.minStack)-1]
    }
    this.stack = this.stack[0:len(this.stack)-1]
}


func (this *MinStack) Top() int {
    return this.stack[len(this.stack)-1]
}


func (this *MinStack) GetMin() int {
    return this.minStack[len(this.minStack)-1]
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
```