```
type MinStack struct {
	stack []int
	min   []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(x int) {
	this.stack = append(this.stack, x)

	if len(this.min) > 0 {
		min := this.min[len(this.min)-1]
		if min > x {
			this.min = append(this.min, x)
		} else {
			this.min = append(this.min, min)
		}
	} else {
		this.min = append(this.min, x)
	}

}

func (this *MinStack) Pop() {
	this.stack = this.stack[0 : len(this.stack)-1]
	this.min = this.min[0 : len(this.min)-1]
}

func (this *MinStack) Top() int {
	return this.stack[len(this.stack)-1]
}

func (this *MinStack) GetMin() int {
	return this.min[len(this.min)-1]
}

```
