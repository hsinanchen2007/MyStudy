```golang
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

//	215
func findKthLargest(nums []int, k int) int {
	h := &IntMinHeap{}
	for _, num := range nums {
		heap.Push(h, num)
		if h.Len() > k {
			heap.Pop(h)
		}
	}
	x := heap.Pop(h)
	return x.(int)
}

```
