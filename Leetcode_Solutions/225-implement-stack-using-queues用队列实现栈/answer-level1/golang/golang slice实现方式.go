### 解题思路
此处撰写解题思路

### 代码

```golang
type MyStack struct {
    data []int
    size int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        data: make([]int, 0),
        size: -1,
    }
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.size++
    this.data = append(this.data, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    if this.Empty() { return -1 }
    v := this.data[this.size]
    this.size--
    if this.size == -1 {
        this.data = make([]int, 0)
    } else {
        this.data = this.data[:this.size+1]
    }
    return v
}


/** Get the top element. */
func (this *MyStack) Top() int {
    if this.Empty() { return -1 }
    return this.data[this.size]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return this.size == -1
}