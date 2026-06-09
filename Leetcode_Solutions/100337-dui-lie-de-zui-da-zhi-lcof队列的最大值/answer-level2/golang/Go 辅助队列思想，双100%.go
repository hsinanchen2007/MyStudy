### 解题思路
设置辅助队列，用于存放递减的最大值队列。
当push元素时，使用该元素和最大值队列队尾的元素比较，如果小于队尾元素，直接入队，否则从最大值队列尾部将小于该元素的数据全部弹出，在将其添加至最大值队列队尾中。此处无需考虑被弹出的元素，因为他们的值小于当前元素的值，并且入队顺序也早于该元素，因此，无论从队首如何取元素，都不会影响到该最大值队列。在pop元素时，如果该元素值与最大值队列队首的元素相同，则同时将最大值队列的队首元素弹出。

### 代码

```golang
type MaxQueue struct {
	queue []int
	maxQueue []int
}

func Constructor() MaxQueue {
	return MaxQueue{
		queue: make([]int, 0),
		maxQueue: make([]int, 0),
	}
}

func (this *MaxQueue) Max_value() int {
	if len(this.maxQueue) == 0 {
		return -1
	}
	return this.maxQueue[0]
}

func (this *MaxQueue) Push_back(value int)  {
	this.queue = append(this.queue, value)
	for len(this.maxQueue) > 0 && this.maxQueue[len(this.maxQueue)-1] < value {
		this.maxQueue = this.maxQueue[:len(this.maxQueue)-1]
	}
	this.maxQueue = append(this.maxQueue, value)
}

func (this *MaxQueue) Pop_front() int {
	if len(this.queue) == 0 {
		return -1
	}
	v := this.queue[0]
	if this.maxQueue[0] == v {
		this.maxQueue = this.maxQueue[1:]
	}
	this.queue = this.queue[1:]
	return v
}
```