### 解题思路
最大堆最小堆

### 代码

```golang

//	295
type IntMinHeap []int

func (pq *IntMinHeap) Len() int {
	return len(*pq)
}
func (pq *IntMinHeap) Less(i, j int) bool {
	return (*pq)[i] < (*pq)[j]
}
func (pq *IntMinHeap) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *IntMinHeap) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

func (pq *IntMinHeap) Pop() interface{} {
	n := len(*pq) - 1
	x := (*pq)[n]
	*pq = (*pq)[:n]
	return x
}
func (pq *IntMinHeap) Peek() int {
	return (*pq)[0]
}

type IntMaxHeap []int

func (pq *IntMaxHeap) Len() int {
	return len(*pq)
}
func (pq *IntMaxHeap) Less(i, j int) bool {
	return (*pq)[i] > (*pq)[j]
}
func (pq *IntMaxHeap) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *IntMaxHeap) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

func (pq *IntMaxHeap) Pop() interface{} {
	n := len(*pq) - 1
	x := (*pq)[n]
	*pq = (*pq)[:n]
	return x
}

func (pq *IntMaxHeap) Peek() int {
	return (*pq)[0]
}


type MedianFinder struct {
	minHeap *IntMinHeap //	维护较大的一半元素
	maxHeap *IntMaxHeap //	维护较小的一半元素
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
	return MedianFinder{
		minHeap: &IntMinHeap{},
		maxHeap: &IntMaxHeap{},
	}
}

func (mf *MedianFinder) AddNum(num int) {
	// 保证maxHeap元素数量比minHeap大1
	if (mf.maxHeap.Len()+mf.minHeap.Len())%2 == 0 {
		// 奇数次添加,放入maxHeap
		if mf.minHeap.Len() > 0 && mf.minHeap.Peek() < num {
			heap.Push(mf.minHeap, num)
			num = heap.Pop(mf.minHeap).(int)
		}
		heap.Push(mf.maxHeap, num)
	} else {
		// 偶数次添加,放入minHeap
		if mf.maxHeap.Len() > 0 && mf.maxHeap.Peek() > num {
			heap.Push(mf.maxHeap, num)
			num = heap.Pop(mf.maxHeap).(int)
		}
		heap.Push(mf.minHeap, num)
	}
}

func (mf *MedianFinder) FindMedian() float64 {
	if (mf.minHeap.Len()+mf.maxHeap.Len())%2 == 1 {
		return float64(mf.maxHeap.Peek())
	} else {
		return float64(mf.maxHeap.Peek()+mf.minHeap.Peek()) / 2
	}
}
```