### 解题思路
此处撰写解题思路
	基本思路就是保持队列头部的值最大，可以使用逻辑形式上的双端队列，也可以直接使用数组就可以。
### 代码

```golang

// 定义一个双端队列
type DequeArray []int

func NewDequeue() *DequeArray {
	arr := make([]int,0)
	return (*DequeArray)(&arr)
}

func (deq *DequeArray) RemoveLast() {
	if len(*deq) == 0 {
		return
	}

	*deq = (*deq)[:len(*deq)-1]
}

func (deq *DequeArray) RemoveFirst() {
	if len(*deq) == 0 {
		return
	}

	*deq = (*deq)[1:]
}

func (deq *DequeArray) GetFirst() int {
	if len(*deq) == 0 {
		panic("queue is empty")
	}

	return (*deq)[0]
}

func (deq *DequeArray) GetLast() int {
	if len(*deq) == 0 {
		panic("queue is empty")
	}

	return (*deq)[len(*deq)-1]
}

func (deq *DequeArray) AddLast(v int) {
	*deq = append(*deq,v)
}

func (deq *DequeArray) IsEmpty() bool {
	return len(*deq) == 0
}

func maxSlidingWindow(nums []int, k int) []int {
	numLen := len(nums)
	if numLen <= 0 {
		return nil
	}

	queue := NewDequeue()
	result := make([]int,0)

	for i:= 0;i < numLen;i++ {
		if !queue.IsEmpty() && queue.GetFirst() <= i-k {
			// 从k的下一个位置开始移除窗口外面的值
			queue.RemoveFirst()
		}

		for !queue.IsEmpty() && nums[queue.GetLast()] < nums[i] {
			// 不断移除窗口内之前较小的值
			queue.RemoveLast()
		}
		queue.AddLast(i)
		if i >= k-1 {
			// 从K处开始加入到结果中
			result = append(result,nums[queue.GetFirst()])
		}
	}

	return result
}
```