### 解题思路
使用偏移记录栈顶

### 代码

```golang
type MyStack struct {
    val []int
    pos int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        val: make([]int, 0),
        pos: 0,
    }
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    if len(this.val) <= this.pos {
        this.val = append(this.val, x)
    } else {
        this.val[this.pos] = x
    }
    this.pos++
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    this.pos--
    return this.val[this.pos]
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.val[this.pos-1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    if this.pos == 0 {
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