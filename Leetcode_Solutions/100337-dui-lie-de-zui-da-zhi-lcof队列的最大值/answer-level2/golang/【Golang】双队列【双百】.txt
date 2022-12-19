![微信截图_20200306185955.png](https://pic.leetcode-cn.com/d2db6d9f93330c32031fe72ee24fc4ac45422089303cb808585726186ed63c0e-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200306185955.png)

# 解题思路
- **双队列**
 	- 入队
 	 	- q1 : 单向队列，用于存储进队的值
 	 	- max ：双向队列，较大值进队，较小值出队，用于存储最大值，呈递减序列
 	- 出队
 	 	- q1 : 首部出队
 	 	- max：队列的首部与 q1 出队的值作比较，如果相同，那么一起出队
 	 - 若队列为空，pop_front 和 max_value 返回 -1 
---
# 代码
--执行用时：88 ms --内存消耗：7.8 MB
```go
type MaxQueue struct {
    q1 []int
    max []int
}

func Constructor() MaxQueue {
    return MaxQueue{
        make([]int,0),
        make([]int,0),
    }
}

func (this *MaxQueue) Max_value() int {
    if len(this.max) == 0{
        return -1
    }
    return this.max[0]
}

func (this *MaxQueue) Push_back(value int)  {
    this.q1 = append(this.q1,value)
    for len(this.max) != 0 && value > this.max[len(this.max)-1]{
        this.max = this.max[:len(this.max)-1]
    }
    this.max = append(this.max,value)
}

func (this *MaxQueue) Pop_front() int {
    n := -1
    if len(this.q1) != 0{
        n = this.q1[0]
        this.q1 = this.q1[1:]
        if this.max[0] == n{
            this.max = this.max[1:]
        }
    }
    return n
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Max_value();
 * obj.Push_back(value);
 * param_3 := obj.Pop_front();
 */
```