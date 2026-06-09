### 解题思路
最小堆

### 代码

```golang

type KthLargest struct {
	k       int
	minHeap *IntMinHeap
}

func Constructor(k int, nums []int) KthLargest {
	ktl := KthLargest{minHeap: &IntMinHeap{}, k: k}
	for _, n := range nums {
		heap.Push(ktl.minHeap, n)
		if ktl.minHeap.Len() > k {
			heap.Pop(ktl.minHeap)
		}
	}
	return ktl
}

func (ktl *KthLargest) Add(val int) int {
	heap.Push(ktl.minHeap, val)
	if ktl.minHeap.Len() > ktl.k {
		heap.Pop(ktl.minHeap)
	}
	return ktl.minHeap.Peek()
}

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

```