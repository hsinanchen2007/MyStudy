### 解题思路
越优化越慢，脑科疼，但是思路应该没毛病。
这道题应该只能平均O(1)
思路1：
 最简单的思路是记录 max int   如果pop了max 那么重遍历算一下max，这样只有popmax时 是O(n) 其余是O(1) ， 平均可以算是O(1) ， 当然如果是一个[5,4,3,2,1]队列 那就不行了。
思路2:
用个maxlist队列，记录最大，下边代码就是，注释写的比较清楚。

### 代码

```golang
import "container/list"

type MaxQueue struct {
	maxlist []int   
	ll      *list.List
}

func Constructor() MaxQueue {
	return MaxQueue{
		maxlist: []int{},
		ll:      list.New(),
	}
}

func (this *MaxQueue) Max_value() int {
	if len(this.maxlist) == 0 {
		return -1
	}
	return this.maxlist[0]
}

func (this *MaxQueue) Push_back(value int) {
	this.ll.PushBack(value)
	if len(this.maxlist) != 0 && value >= this.maxlist[0] {
		// 如果新加入的最大，那么记录最大队列可以清空 只保留一个就ok
		// 因为pop的先进入的，不会影响当前队列最大的
		this.maxlist = []int{value}
	} else {
		// 如果新加入的不是最大，那么删除调比它小的，然后把它加到后边
		// 就是这里破坏了 O(1) 复杂度  所以实际上只是平均是O(1)
		// 如果push的是递减的队列 [5,4,3,2,1] 那将是O(1)
		// 如果push的是[5,3,2,1,4]  插入前面的都是O(1) ， 插入4的时候是n-1， 所以平均是O(1)
		for i := len(this.maxlist)-1; i>=0 ;i-- {
			 
			if this.maxlist[i] < value {
				//删掉最后一个
				this.maxlist = this.maxlist[0:len(this.maxlist)-1]
			} else {
				break
			}
		}
		this.maxlist = append(this.maxlist,value)
	}
}

func (this *MaxQueue) Pop_front() int {
	if this.ll.Len() == 0 {
		return -1
	}
	b := this.ll.Front().Value.(int)
	this.ll.Remove(this.ll.Front())
	if b == this.maxlist[0] {
		this.maxlist = this.maxlist[1:]
	}
	return b
}
/**
 * Your MaxQueue object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Max_value();
 * obj.Push_back(value);
 * param_3 := obj.Pop_front();
 */
```