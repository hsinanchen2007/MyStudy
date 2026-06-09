### 代码

```golang
type MaxQueue struct {
    queue,help []int
}


func Constructor() MaxQueue {
    return MaxQueue{[]int{},[]int{}}
}


func (this *MaxQueue) Max_value() int {
    if len(this.queue)==0{
        return -1
    }
    return this.help[0]
}


func (this *MaxQueue) Push_back(value int)  {
    this.queue=append(this.queue,value)
    if len(this.help)==0||value<=this.help[len(this.help)-1]{
        this.help=append(this.help,value)
    }else{
        for i:=len(this.help)-1;i>=0;i--{
            if this.help[i]>=value{
                this.help=append(this.help[:i+1],value)
                break
            } else if i==0{
                this.help=[]int{value}
                break                
            }
        }
    }
}


func (this *MaxQueue) Pop_front() int {
    if len(this.queue)==0{
        return -1
    }
    t:=this.queue[0]
    this.queue=this.queue[1:]
    if this.help[0]==t{
        this.help=this.help[1:]
    }
    return t
}


/**
 * Your MaxQueue object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Max_value();
 * obj.Push_back(value);
 * param_3 := obj.Pop_front();
 */
```