### 解题思路
使用Go []int 来模拟队列
首先栈的特性是先进后出
Push：压入元素，使用list append即可模拟
Top：获取栈顶元素，即list最后一个元素
Pop: 弹出栈顶元素， 即移除list最后一个元素， 并return该元素
Empty: 判断是否为空， list长度是否为0

### 代码

```golang
package main

type MyStack struct {
	Lst    []int
	Length int
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	v := make([]int, 0, 1024)
	return MyStack{Lst: v}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	this.Lst = append(this.Lst, x)
	this.Length += 1
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	
	this.Length -= 1
    v := this.Lst[this.Length]
	this.Lst = this.Lst[:this.Length]
	return v
}

/** Get the top element. */
func (this *MyStack) Top() int {
	return this.Lst[this.Length-1]
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return this.Length <= 0
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