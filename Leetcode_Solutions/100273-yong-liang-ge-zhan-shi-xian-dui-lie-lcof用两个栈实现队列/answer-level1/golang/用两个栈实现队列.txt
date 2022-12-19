### 解题思路
此处撰写解题思路

### 代码

```golang
type CQueue struct {
	stack1 []int
	stack2 []int
}


func Constructor() CQueue {
	return CQueue{}
}

// 插入的时候 如果栈1 为空 直接插
// 如果栈1 不为空 先把栈1 依次弹出放入栈2 插入value  然后再从栈2 依次弹回栈1
func (this *CQueue) AppendTail(value int)  {
	for len(this.stack1) > 0{
		n := len(this.stack1)
		this.stack2 = append(this.stack2,this.stack1[n-1])
		this.stack1 = this.stack1[:n-1]
	}

	this.stack1 = append(this.stack1,value)

	for len(this.stack2) > 0 {
		n := len(this.stack2)
		this.stack1 = append(this.stack1,this.stack2[n-1])
		this.stack2 = this.stack2[:n-1]
	}
}

// 从栈1 弹出
func (this *CQueue) DeleteHead() int {
	n := len(this.stack1)
	if n == 0 {
		return -1
	}

	defer func() {
		this.stack1 = this.stack1[:n-1]
	}()

	return this.stack1[n-1]
}
```