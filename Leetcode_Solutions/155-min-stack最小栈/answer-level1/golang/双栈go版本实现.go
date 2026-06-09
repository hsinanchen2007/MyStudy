### 解题思路
此处撰写解题思路
用两个slice，一个保存数据，一个保存每次插入的最小值
### 代码

```golang
type MinStack struct {
    data []int
    mindata []int
    size int
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{
        data:make([]int, 0),
        mindata:make([]int, 0),
    }
}


func (this *MinStack) Push(x int)  {
    this.data = append(this.data, x)
   
    if len(this.mindata)==0 {
        this.mindata = append(this.mindata, x)
    } else if this.mindata[this.size-1] > x {
        this.mindata = append(this.mindata, x)
    } else {
        this.mindata = append(this.mindata, this.mindata[this.size-1])
    }
     this.size+=1
}


func (this *MinStack) Pop()  {
    if this.size > 0 {
        this.data = this.data[0:this.size-1]
        this.mindata = this.mindata[0:this.size-1]
        this.size-=1
    }
}


func (this *MinStack) Top() int {
    var res int
    if this.size > 0 {
        res = this.data[this.size-1]
    }
    return res
}


func (this *MinStack) GetMin() int {
   if this.size > 0 {
        return this.mindata[this.size-1]
   }
   return -1
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