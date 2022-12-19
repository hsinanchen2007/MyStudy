### 解题思路
枚举, 最大堆

### 代码

```golang
//	373

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	maxHeap := &TupleMaxHeap{}
	for _, n1 := range nums1 {
		for _, n2 := range nums2 {
			heap.Push(maxHeap, Tuple{
				x: n1,
				y: n2,
			})
			if maxHeap.Len() > k {
				heap.Pop(maxHeap)
			}
		}
	}
	res := make([][]int, maxHeap.Len())
	i := maxHeap.Len() - 1
	for maxHeap.Len() > 0 {
		top := heap.Pop(maxHeap).(Tuple)
		res[i] = []int{top.x, top.y}
		i--
	}
	return res
}

type Tuple struct {
	x int
	y int
}

type TupleMaxHeap []Tuple

func (pq *TupleMaxHeap) Len() int {
	return len(*pq)
}
func (pq *TupleMaxHeap) Less(i, j int) bool {
	return (*pq)[i].x+(*pq)[i].y > (*pq)[j].x+(*pq)[j].y
}
func (pq *TupleMaxHeap) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *TupleMaxHeap) Push(x interface{}) {
	*pq = append(*pq, x.(Tuple))
}

func (pq *TupleMaxHeap) Pop() interface{} {
	n := len(*pq) - 1
	x := (*pq)[n]
	*pq = (*pq)[:n]
	return x
}
func (pq *TupleMaxHeap) Peek() Tuple {
	return (*pq)[0]
}

```