### 解题思路
明确栈和队列的特点
栈是FILO，队列则是FIFO，根据两者特点，用go的内置slice操作完成栈转队列，队列转栈的操作。

### 代码

```golang
type MyStack struct {
    arr []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    if this.arr == nil {
        this.arr = make([]int, 0)
    }
    this.arr = append(this.arr, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    if this.arr == nil || len(this.arr) == 0 {
        return 0
    }
    res := this.arr[len(this.arr) - 1]
    this.arr = this.arr[:len(this.arr)- 1]
    return res
}


/** Get the top element. */
func (this *MyStack) Top() int {
    if this.arr == nil || len(this.arr) == 0 {
        return 0
    }
    return this.arr[len(this.arr) - 1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    if this.arr == nil || len(this.arr) == 0 {
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