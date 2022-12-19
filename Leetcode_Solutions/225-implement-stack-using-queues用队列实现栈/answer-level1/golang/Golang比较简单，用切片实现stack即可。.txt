### 解题思路
Golang比较简单，用切片实现stack即可。pop出栈只要将切片最后一个元素去掉即可（items[0 : len(items)-1]）。

执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2 MB, 在所有 Go 提交中击败了100.00%的用户

### 代码

```golang
type MyStack struct {
	Items []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{ Items:[]int{} }
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	if this == nil {
		*this =  Constructor()
	}
	this.Items = append(this.Items, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	if this == nil {
		*this =  Constructor()
	}
	if !this.Empty() {
		top := this.Items[len(this.Items) - 1]

		items := this.Items
		this.Items = items[0 : len(items)-1]

		return top
	}
	return 0
}


/** Get the top element. */
func (this *MyStack) Top() int {
	if this == nil {
		*this =  Constructor()
	}
	if !this.Empty() {
		return this.Items[len(this.Items) - 1]
	}
	return 0
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	if this == nil {
		*this =  Constructor()
	}
	if len(this.Items) >0 {
		return false
	} else {
		return true
	}
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