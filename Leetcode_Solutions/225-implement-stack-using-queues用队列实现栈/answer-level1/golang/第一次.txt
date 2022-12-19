### 解题思路
此处撰写解题思路
辛辛苦苦写的解析没了...
### 代码

```golang
import (
	"fmt"
	"testing"
)

type MyStack struct {
	enque [] int
	deque [] int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{[] int {}, [] int {}}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
	//进栈的时候 将元素压入到进队切片中即可
	this.enque = append(this.enque, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	// 出栈的时候, 相当于弹出进队切片中最后一个元素
	lenth := len(this.enque)
	for i := 0; i < lenth-1; i++ {
		this.deque = append(this.deque, this.enque[0])
		this.enque = this.enque[1:]
	}
	topEle := this.enque[0]
	this.enque = this.deque
	this.deque = nil
	return topEle
}


/** Get the top element. */
func (this *MyStack) Top() int {
	topEle := this.Pop()
	this.enque = append(this.enque, topEle)
	return topEle
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

 func Test_Problem225(t *testing.T) {
	obj := Constructor()
	fmt.Printf("obj = %v\n", obj)
	param5 := obj.Empty()
	fmt.Printf("param_5 = %v\n", param5)
	obj.Push(2)
	fmt.Printf("obj = %v\n", obj)
	obj.Push(10)
	fmt.Printf("obj = %v\n", obj)
	param2 := obj.Pop()
	fmt.Printf("param_2 = %v\n", param2)
	param3 := obj.Top()
	fmt.Printf("param_3 = %v\n", param3)
	param4 := obj.Empty()
	fmt.Printf("param_4 = %v\n", param4)
}
```