维护一个有序min值的stack，弹出的时候检查是否是min的栈顶
```
type MinStack struct {
    data []int
    min []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
    var stack MinStack
    return stack
}
func (this *MinStack)Push(data int){
    if len(this.min)==0 || this.min[len(this.min)-1] >= data {
        this.min = append(this.min,data)
    }
    this.data = append(this.data,data)
}

func (this *MinStack)Pop (){
    if this.min[len(this.min)-1]  this.Top() {
        this.min = this.min[0:len(this.min)-1]
    }
    if !this.is_empty() {
        this.data = this.data[0:len(this.data)-1]
    }
}

func (this *MinStack) Top() int {
    if this.is_empty(){
        return 0
    }
    return this.data[len(this.data)-1]
}

func (this *MinStack) GetMin() int {
    if this.is_empty(){
        return 0
    }
    return this.min[len(this.min)-1]
}

func (this *MinStack)is_empty() bool {
    return len(this.data)==0
}



/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
```
