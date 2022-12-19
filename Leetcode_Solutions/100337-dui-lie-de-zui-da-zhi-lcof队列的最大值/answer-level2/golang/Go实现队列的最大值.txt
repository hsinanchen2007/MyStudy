

```golang
type MaxQueue struct {
    queue []int
    help  []int
}

func Constructor() MaxQueue {
    return MaxQueue{}
}

func (this *MaxQueue) Max_value() int {
    if len(this.help)==0{
        return -1
    }
    return this.help[0]
}

func (this *MaxQueue) Push_back(value int)  {
    this.queue = append(this.queue,value)
    if len(this.help)==0{
        this.help = append(this.help,value)
    }else{
        for len(this.help)!=0&&this.help[len(this.help)-1]<value{ 
        this.help = this.help[:len(this.help)-1] 
        }
        this.help = append(this.help,value)
    }
}

func (this *MaxQueue) Pop_front() int {
    if len(this.queue)==0{
        return -1
    }
    num :=this.queue[0]
    this.queue = this.queue[1:]
    if this.help[0]==num{
        this.help = this.help[1:]
    }
    return num
}


/**
 * Your MaxQueue object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Max_value();
 * obj.Push_back(value);
 * param_3 := obj.Pop_front();
 */
```