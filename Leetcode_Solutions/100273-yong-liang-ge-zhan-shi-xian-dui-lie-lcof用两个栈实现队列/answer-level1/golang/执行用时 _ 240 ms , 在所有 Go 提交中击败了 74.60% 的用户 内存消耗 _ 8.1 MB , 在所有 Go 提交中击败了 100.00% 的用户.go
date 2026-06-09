### 解题思路
此处撰写解题思路

### 代码

```golang
type CQueue struct {
	stack []int
	sLen  int
}

func Constructor() CQueue {
	return CQueue{}
}

func (this *CQueue) AppendTail(value int) {
	this.stack = append(this.stack, value)
	this.sLen++
}

func (this *CQueue) DeleteHead() int {
	if this.sLen == 0 {
		return -1
	}
	del := this.stack[0]
	this.stack = this.stack[1:]
	this.sLen--
	return del
}
```