解法：

1. appendTail 的时候 s1 添加到末尾；
2. deleteHead 的时候判断 s1 为空则返回 -1, 不为空则把 s1 的数据出栈到 s2, s2 出栈 top 元素, 然后 s2 剩余的元素 pop 到 s1。

***注意：数据结构虽然使用 slice 实现, 但是模拟的必须是栈的操作!***

```go []
type CQueue struct {
	s1, s2 []int // 尾插, 尾取即可以实现栈
}

func Constructor() CQueue {
	return CQueue{}
}

func (this *CQueue) AppendTail(value int) {
	this.s1 = append(this.s1, value)
}

func (this *CQueue) DeleteHead() int {
	if len(this.s1) == 0 {
		return -1
	}

	for len(this.s1) != 0 {
		this.s2 = append(this.s2, this.s1[len(this.s1)-1])
		this.s1 = this.s1[:len(this.s1)-1]
	}

	front := this.s2[len(this.s2)-1]
	this.s2 = this.s2[:len(this.s2)-1]

	for len(this.s2) != 0 {
		this.s1 = append(this.s1, this.s2[len(this.s2)-1])
		this.s2 = this.s2[:len(this.s2)-1]
	}

	return front
}

```

