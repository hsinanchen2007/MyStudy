### 解题思路
切片实现栈的操作：
    1. push操作: 在切片尾部添加元素
    2. empty操作：也就是判断栈是否空， 只需要 判断切片的长度是否等于0
    3. pop: 栈不空的情况，删除切片尾部元素
    4. top: 栈不空的情况，返回切片尾部元素
本题的不足：
    当栈为空时候，pop操作是返回的-1。 -1有可能是业务数据

### 代码

```golang
type MyStack struct {
    ArrInt []int

}


/** Initialize your data structure here. */
func Constructor() MyStack {
    instance := MyStack{}
    instance.ArrInt = make([]int, 0)
    return instance
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.ArrInt = append(this.ArrInt, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    if this.Empty(){
        return  -1
    }
    item := this.ArrInt[len(this.ArrInt)-1]
    this.ArrInt = this.ArrInt[0:len(this.ArrInt)-1]
    return item
}


/** Get the top element. */
func (this *MyStack) Top() int {
    if this.Empty(){
        return  -1
    }
    return this.ArrInt[len(this.ArrInt)-1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.ArrInt) == 0
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