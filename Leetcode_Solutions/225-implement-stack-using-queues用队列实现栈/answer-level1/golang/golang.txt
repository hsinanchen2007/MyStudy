### 解题思路
此处撰写解题思路

### 代码

```golang
type MyStack struct {
    list []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{list:make([]int,0)}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.list = append(this.list, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    val := this.Top()
    this.list = this.list[:len(this.list)-1]
    return val
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.list[len(this.list)-1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.list)==0
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