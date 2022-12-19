用链表维护单调递减数列
保存每个元素在列表中的位置，删的时候可以更快
```
type MaxQueue struct {
    queue []int
    maxValue *list.List
    ele []*list.Element
}


func Constructor() MaxQueue {
    return MaxQueue{
        queue: []int{},
        maxValue: list.New(),
        ele: []*list.Element{},
    }
}


func (this *MaxQueue) Max_value() int {
    if this.maxValue.Len() == 0 {
        return -1
    }
    return this.maxValue.Front().Value.(int)
}


func (this *MaxQueue) Push_back(value int)  {
    this.queue = append(this.queue, value)
    for e := this.maxValue.Front(); e != nil; e = e.Next() {
        if value >= e.Value.(int) {
            nw := this.maxValue.InsertBefore(value, e)
            this.ele = append(this.ele, nw)
            return
        }
    }
    nw := this.maxValue.PushBack(value)
    this.ele = append(this.ele, nw)
}


func (this *MaxQueue) Pop_front() int {
    if len(this.queue) == 0 {
        return -1
    }
    ret := this.queue[0]
    
    this.maxValue.Remove(this.ele[0])
    this.ele = this.ele[1:]
    this.queue = this.queue[1:]
    return ret
}
```
