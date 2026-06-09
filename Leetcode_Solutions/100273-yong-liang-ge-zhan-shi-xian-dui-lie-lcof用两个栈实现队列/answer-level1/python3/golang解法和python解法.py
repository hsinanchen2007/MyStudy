使用两个栈，一个栈当作队尾，用作输入，另一个栈当作队头，用于输出

队列的特点是先进先出，尾进投出
栈的特点是先进后出，先进的元素放入栈底，后进的元素放入栈顶

从<输入栈>输出到<输出栈>后，原本位于<输入栈> 栈底（先进入）的元素，又跑到了<输出栈>的栈顶，因此，出队列的操作只需要将<输出栈>的栈顶元素 输出就好 

主要说一下出队操作
1. 当两个栈都为空的时候，返回－1
2. 当输出栈不为空的时候，输出<输出栈>的栈顶元素
3. 当输出栈为空，输入栈不为空的时候，将<输入栈>的所有元素输出到<输出栈> ,然后就相当于2的情况，输出<输出栈>的栈顶元素


```golang []
type CQueue struct {
	input  []int
	output []int
}

func Constructor() CQueue {
	return CQueue{
		make([]int, 0, 100),
		make([]int, 0, 100),
	}

}

func (this *CQueue) AppendTail(value int) {
	this.input = append(this.input, value)
}

func (this *CQueue) DeleteHead() int {
	if len(this.input) == 0 && len(this.output) == 0 {
		return -1
	}
	if len(this.output) != 0 {
		x := this.output[len(this.output)-1]
		this.output = this.output[:len(this.output)-1]
		return x
	}
	for len(this.input) > 0 {
		this.output = append(this.output, this.input[len(this.input)-1])
		this.input = this.input[:len(this.input)-1]
	}
	x := this.output[len(this.output)-1]
	this.output = this.output[:len(this.output)-1]
	return x
}

```
```python3 []
class CQueue:
    
    def __init__(self):
        self.input=[]
        self.output=[]


    def appendTail(self, value):
        self.input.append(value)


    def deleteHead(self):
        if len(self.input)==0 and len(self.output)==0:
            return -1
        elif len(self.output)!=0:
            return self.output.pop()
        else:
            while len(self.input)!=0:
                self.output.append(self.input.pop())
            return self.output.pop()
```

