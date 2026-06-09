### 解题思路
此处撰写解题思路

### 代码

```golang
type MinStack struct {
    data []int
    help []int
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{}
}


func (this *MinStack) Push(x int)  {
     this.data = append(this.data,x)
    if len(this.help)==0{
        this.help = append(this.help,x)
    }else if this.help[len(this.help)-1]<x{
        this.help = append(this.help,this.help[len(this.help)-1])
    }else{
         this.help = append(this.help,x)
    }
}


func (this *MinStack) Pop()  {
     this.data = this.data[:len(this.data)-1]
     this.help = this.help[:len(this.help)-1] 
}


func (this *MinStack) Top() int {
     return this.data[len(this.data)-1]
}


func (this *MinStack) GetMin() int {
    return this.help[len(this.help)-1]
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