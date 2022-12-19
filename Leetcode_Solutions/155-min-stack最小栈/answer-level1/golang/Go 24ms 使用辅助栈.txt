* 当辅助栈为空的时候直接放入新数据
* push的时候如果该元素小于等于辅助栈顶元素，则将其推入辅助栈
* 出栈的时候如果出栈元素等于辅助栈栈顶元素辅助栈也跟着出栈

```
type MinStack struct {
	data []int
	help []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{[]int{}, []int{}}
}

func (this *MinStack) Push(x int) {
	if len(this.data) == 0 || x <= this.GetMin() {
		this.help = append(this.help, x)
	}
	this.data = append(this.data, x)
}

func (this *MinStack) Pop() {
	x := this.data[len(this.data)-1]
	this.data = this.data[:len(this.data)-1]
	if x == this.GetMin() {
		this.help = this.help[:len(this.help)-1]
	}
}

func (this *MinStack) Top() int {
	return this.data[len(this.data)-1]
}

func (this *MinStack) GetMin() int {
	return this.help[len(this.help)-1]
}
```

| 提交时间 | 提交结果 | 执行用时 | 内存消耗 | 语言   |
| :------- | :------- | :------- | :------- | :----- |
| 几秒前   | 通过     | 24 ms    | 8.3 MB   | Golang |