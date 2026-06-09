看了下题解，没有用我这个方法的。所以写出来参考一下：
type MinStack struct {
	data *Stack //封装了一个栈
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(x int) {
	if this.data == nil {
		this.data = &Stack{
			Val: x,
			Min: x,
		}
	} else {
		min := this.data.Min
		if min > x {
			min = x
		}
		d := Stack{
			Val:    x,
			Father: this.data,
			Min:    min,
		}
		this.data = &d
	}
}

func (this *MinStack) Pop() {
	if this.data.Father != nil {
		this.data = this.data.Father
	} else {
		this.data = nil
	}
}

func (this *MinStack) Top() int {
	if this.data != nil {
		return this.data.Val
	}
	return 2147483647
}

func (this *MinStack) GetMin() int {
	if this.data != nil {
		return this.data.Min
	}
	return 2147483647

}

type Stack struct {
	Val    int      //数值
	Father *Stack   //指向父亲的指针
	Min    int      //当前最小的值
}
