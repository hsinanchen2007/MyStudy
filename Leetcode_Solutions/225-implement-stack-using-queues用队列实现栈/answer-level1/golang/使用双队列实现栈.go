### 解题思路

根据 [@jalan](/u/jalan/)大佬的题解一自己实现了一遍，只简单修改了golang的一些写法和变量名

### 代码

```golang
type MyStack struct {
    q1 [] int
    q2 [] int
    top int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    var mystack MyStack
    return mystack
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.q1 = append(this.q1, x)
    this.top = x
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    length1 := len(this.q1)
    for i := 0; i < length1 - 1; i++ {
        item := this.q1[0]
        this.top = item
        this.q1 = this.q1[1:]
        this.q2 = append(this.q2, item)
    }
    target := this.q1[0]
    this.q1,this.q2 = this.q2,make([]int, 0)
    return target
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.top
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.q1) == 0
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