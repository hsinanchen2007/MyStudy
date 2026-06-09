### 解题思路
最大堆

### 代码

```golang
func lastStoneWeight(stones []int) int {
	maxHeap := &IntMaxHeap{}
	for _, s := range stones {
		heap.Push(maxHeap, s)
	}
	for maxHeap.Len() > 1 {
		big := heap.Pop(maxHeap).(int)
		sml := heap.Pop(maxHeap).(int)
		if big > sml {
			heap.Push(maxHeap, big - sml)
		}
	}
	if maxHeap.Len() > 0 {
		return maxHeap.Peek()
	}
	return 0
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
```