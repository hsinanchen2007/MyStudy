### 解题思路
利用标准库里的`container/list`容器实现，很省事，但空间效率不好。
仅供参考。

### 代码

```golang
type MyStack struct {
    Data *list.List
}


/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{list.New()}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
	this.Data.PushFront(x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	ele := this.Data.Front()
	this.Data.Remove(ele)
	return ele.Value.(int)
}


/** Get the top element. */
func (this *MyStack) Top() int {
	return this.Data.Front().Value.(int)
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return this.Data.Len() == 0
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