### 解题思路
此处撰写解题思路
主要利用了go的切片实现了栈，过程比较简单就是对切片最后一个单位进行添加和删除操作

### 代码

```golang
type MyStack struct {
	data []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{
		data: make([]int,0),
	}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
	this.data = append(this.data,x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	if len(this.data) == 0 {
		return -1
	}
	res := this.data[len(this.data) - 1]
	this.data = this.data[:len(this.data)-1]
	return res
}


/** Get the top element. */
func (this *MyStack) Top() int {
	if len(this.data) == 0{
		return -1
	}
	return this.data[len(this.data)-1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return len(this.data) ==0
}
```