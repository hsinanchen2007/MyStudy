### 解题思路
用container/list的来模拟stack。
注意golang的反射语法.
不能用强制转换。

### 代码

```golang

type MyStack struct {
	list *list.List
}


/** Initialize your data structure here. */
func Constructor() MyStack {
	list := list.New()
	return MyStack{list:list}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
	this.list.PushBack(x)

}


func (this *MyStack) Pop() int {
	ans := this.list.Back().Value.(int)
	this.list.Remove(this.list.Back())
	return ans
}


/** Get the top element. */
func (this *MyStack) Top() int {
	return this.list.Back().Value.(int)

}



/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return this.list.Len() == 0
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