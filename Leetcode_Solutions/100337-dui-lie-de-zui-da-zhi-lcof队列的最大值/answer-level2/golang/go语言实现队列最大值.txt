### 解题思路
队列的最大值和栈的最大值的实现思路不同，实现也更复杂一些。
采用单调递减的辅助队列，辅助队列的第一个数是队列的最大值，第二个数是辅助队列第一个数后面队列中数据的最大值，第三个数是辅助队列第二个数后面队列中数据的最大值，以此类推。
例如：
```
队列:[8,3,5,4,1,2]
辅助队列：[8,5,4,2]
```

#### 在入队时和辅助队列中的值进行比较。
如果入队的数比辅助队列的第一个数大，则将入队的数放在辅助队列的第一个，队列中后面的数据全部舍弃。
```
队列:[8,3,5,4,1,2] [9]
9入队
辅助队列:[9]
```
如果入队的数比辅助队列中最后一个数大，则将数从后面插入到辅助队列，并移除比该数小的数。
```
队列:[8,3,5,4,1,2] [3]
3入队
辅助队列：[8,5,4,3]
```
###### push_back是不是O(1)的问题
push_back需要遍历辅助队列，但因为辅助队列是单调递减的，value的取值范围是一个常数，所以不论队列长度n为多大，辅助队列的最大长度不会超哥value的取值范围，是一个常数，所以是O(1)。
#### 出队
如果出队的数和辅助队列的头相等，则概数也从辅助队列出队。


![image.png](https://pic.leetcode-cn.com/f084fbd408c2fff8729f7d1c01cd972c99e613b488baac3d01bb8d5a9549cc11-image.png)

### 代码

```golang
type MaxQueue struct {
    Queue []int
    Max []int
    Size int
}

func Constructor() MaxQueue {
    return MaxQueue {
        Queue: []int{},
        Max: []int{},
        Size: 0,
    }
}

func (this *MaxQueue) Max_value() int {
    if this.Size == 0 {
        return -1
    }
    return this.Max[0]

}

func (this *MaxQueue) Push_back(value int)  {
    this.Queue = append(this.Queue, value)
    
    if this.Size == 0 {
        this.Max = append(this.Max, value)
    } else {
        if value >= this.Max[0] {
            this.Max = this.Max[0:0]
            this.Max = append(this.Max, value)
            this.Size++
            return
        }

        for i := len(this.Max) - 1; this.Max[i] < value ; i-- {
            this.Max = this.Max[: i]
        }
        this.Max = append(this.Max, value)
    }

    this.Size++
}

func (this *MaxQueue) Pop_front() int {
    if this.Size == 0 {
        return -1
    }
    num := this.Queue[0]
    if num == this.Max[0] {
        this.Max = this.Max[1:]
    }

    this.Queue = this.Queue[1:]
    this.Size--
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