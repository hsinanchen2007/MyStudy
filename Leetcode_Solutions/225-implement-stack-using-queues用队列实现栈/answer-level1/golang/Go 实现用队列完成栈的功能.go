### 解题思路
此处撰写解题思路
用顺序队列实现栈的基本功能

### 代码

```golang
type MyStack struct {
    data []int  // 用队列实现栈
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.data = append(this.data, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    top := this.data[len(this.data)-1]      // 获取栈顶元素
    this.data = this.data[:len(this.data)-1]// 删除栈顶元素
    return top                              // 返回栈顶元素
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.data[len(this.data)-1]      // 返回栈顶元素
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    if len(this.data) == 0 {
        return true
    }
    return false
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