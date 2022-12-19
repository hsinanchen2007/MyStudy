### 解题思路
突然看到栈和队列 只记得特性了 在go里面似乎可以通过一个数组栈的操作

### 代码

```golang
type MyStack struct {
    enque []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        enque: []int{},
    }
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.enque = append(this.enque,x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    topElem := this.enque[len(this.enque)-1]
    this.enque = this.enque[:len(this.enque)-1]
    return  topElem
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.enque[len(this.enque)-1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.enque) == 0
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