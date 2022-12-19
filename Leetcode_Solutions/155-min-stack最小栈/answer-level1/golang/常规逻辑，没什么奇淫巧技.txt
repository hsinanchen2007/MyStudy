### 解题思路
这个也是借鉴的其他作者的思路。就是多了一个最小值，其他很多人都是使用了双倍空间来换时间的思路，当然也是不错的，我觉得这个方法更直接，容易理解。

1. 在插入的时候去判断一下，当前插入`x`是否小于我的最小值，小于了就先插入一条最小值，并且把我的最小值复制为`x`, 然后再插入真实值，这样首先取出来的值是真实值，而不是我存入的最小值，这里就是如果是最小值，就会插入两次，在 pop 的时候如果情况满足也会同时 pop 两次

2. 由于存入时的顺序，所以取出来的时候肯定先取到真实值，但是由于我在插入的时候有一步操作是
```
	if x <= this.min {
		this.datas = append(this.datas, this.min)
		this.min = x
	}
	this.datas = append(this.datas, x)
```
这里的意思是，如果当前栈顶取到的元素等于最小值，那么它下面的一个元素肯定是最小值。

### 代码

```golang
type MinStack struct {
	datas []int
	min   int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		datas: make([]int, 0),
		min:   math.MaxInt64,
	}
}

func (this *MinStack) Push(x int) {
	if x <= this.min {
		this.datas = append(this.datas, this.min)
		this.min = x
	}
	this.datas = append(this.datas, x)
}

func (this *MinStack) Pop() {
	element := this.datas[len(this.datas)-1:][0] // 拿出栈顶元素
	this.datas = this.datas[:len(this.datas)-1] // 弹出一个栈顶元素
	if element == this.min { // 对比一下，如果相等就在 pop 一次，因为 push 中的关联关系，所以 pop 出来的一定是最小值
		this.min = this.datas[len(this.datas)-1:][0]
		this.datas = this.datas[:len(this.datas)-1]
	}
}

func (this *MinStack) Top() int {
	return this.datas[len(this.datas)-1:][0]
}

func (this *MinStack) GetMin() int {
	return this.min
}
```