### 解题思路
新元素入队后，咱就把之前的元素又重新入了一下队，没别哒

### 代码

```golang
type MyStack struct {
    data []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    s := MyStack{
        data:[]int{},
    }
    return s
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.data=append(this.data,x)
    length := len(this.data)
    for i:=0;i<length-1;i++{
        this.data=append(this.data,this.data[0])
        this.data=this.data[1:]
    }
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    item := this.data[0]
    this.data=this.data[1:]
    return item
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.data[0]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    if len(this.data)==0{
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