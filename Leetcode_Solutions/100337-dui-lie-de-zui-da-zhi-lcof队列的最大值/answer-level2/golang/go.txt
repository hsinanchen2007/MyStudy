### 解题思路
此处撰写解题思路

### 代码

```golang
type MaxQueue struct {
    queue []int
    max []int
}


func Constructor() MaxQueue {
    return MaxQueue{
        queue: []int{},
        max: []int{},
    }
}


func (this *MaxQueue) Max_value() int {
    if len(this.max) == 0{
        return -1
    }else{
        return this.max[0]
    }
}


func (this *MaxQueue) Push_back(value int)  {
    this.queue = append(this.queue,value)
    for len(this.max) != 0 && value > this.max[len(this.max)-1]{
        this.max = this.max[:len(this.max)-1]
    }
    this.max = append(this.max,value)

}


func (this *MaxQueue) Pop_front() int {
    if len(this.queue) == 0{
        return -1
    }
    tail := this.queue[0]
    this.queue = this.queue[1:]
    if tail == this.max[0]{
        this.max = this.max[1:]
    }
    return tail

}


/**
 * Your MaxQueue object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Max_value();
 * obj.Push_back(value);
 * param_3 := obj.Pop_front();
 */
```