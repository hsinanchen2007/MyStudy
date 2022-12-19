![image.png](https://pic.leetcode-cn.com/c8c604c65c943df133b11bf05dda71c0814d7bc939183cceb64accb89e2fca18-image.png)

```
type MaxQueue struct {
    nums []int
}


func Constructor() MaxQueue {
    return MaxQueue{
        nums:make([]int,0,10),
    }
}


func (this *MaxQueue) Max_value() int {
    lenth := len(this.nums)
    if lenth == 0{
        return -1
    }
    res := this.nums[0]
    for i:=0;i<lenth;i++{
        if res < this.nums[i]{
            res = this.nums[i]
        }
    } 
    return res
}


func (this *MaxQueue) Push_back(value int)  {
    this.nums = append(this.nums,value)
}


func (this *MaxQueue) Pop_front() int {
    lenth := len(this.nums)
    if lenth == 0{
        return -1
    }
    res := this.nums[0]
    this.nums = this.nums[1:]
    return res
}
```
