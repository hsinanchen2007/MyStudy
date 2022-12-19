### 解题思路
使用切片来存储数据，最后添加的元素为栈顶。

### 代码

```golang
type MyStack struct {
    data []int
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
    x := this.data[len(this.data)-1]
    this.data = this.data[:len(this.data)-1]
    return x
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.data[len(this.data)-1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.data) == 0
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