type MaxQueue struct {
    Arr []int
    MaxArr []int
}


func Constructor() MaxQueue {
    queue := MaxQueue{}
    queue.Arr=[]int{}
    queue.MaxArr=[]int{}
    return queue
}


func (this *MaxQueue) Max_value() int {
    if len(this.MaxArr)==0 {
        return -1
    }
    return this.MaxArr[0]
}


func (this *MaxQueue) Push_back(value int)  {
    this.Arr=append(this.Arr,value)

    if len(this.MaxArr)==0 {
        this.MaxArr=append(this.MaxArr,value)
        return
    }

    index := len(this.MaxArr)-1

    for index>=0 && this.MaxArr[index]<value {
        index--
    }

    this.MaxArr=append(this.MaxArr[:index+1],value)
}


func (this *MaxQueue) Pop_front() int {
    if len(this.Arr)==0 {
        return -1
    }

    value := this.Arr[0]
    this.Arr=this.Arr[1:]

    if value==this.MaxArr[0] {
        this.MaxArr=this.MaxArr[1:]
    }

    return value
}


/**
 * Your MaxQueue object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Max_value();
 * obj.Push_back(value);
 * param_3 := obj.Pop_front();
 */