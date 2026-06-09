### 解题思路
计数, 最大堆

### 代码

```golang
//	1054
func rearrangeBarcodes(barcodes []int) []int {
	res := make([]int, 0, len(barcodes))
	cntMap := make(map[int]int)
	for _, bc := range barcodes {
		cntMap[bc]++
	}
	maxHeap := &CodeCntMaxHeap{}
	for k, v := range cntMap {
		heap.Push(maxHeap, CodeCnt{
			code: k,
			cnt:  v,
		})
	}
	for maxHeap.Len() > 1 {
		b := heap.Pop(maxHeap).(CodeCnt)
		s := heap.Pop(maxHeap).(CodeCnt)
		res = append(res, b.code, s.code)
		if b.cnt > 1 {
			b.cnt--
			heap.Push(maxHeap, b)
		}
		if s.cnt > 1 {
			s.cnt--
			heap.Push(maxHeap, s)
		}
	}
	if maxHeap.Len() > 0 {
		res = append(res, maxHeap.Peek().code)
	}
	return res
}

type CodeCnt struct {
	code int 
	cnt int
}

type CodeCntMaxHeap []CodeCnt

func (pq *CodeCntMaxHeap) Len() int {
	return len(*pq)
}
func (pq *CodeCntMaxHeap) Less(i, j int) bool {
	return (*pq)[i].cnt > (*pq)[j].cnt
}
func (pq *CodeCntMaxHeap) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *CodeCntMaxHeap) Push(x interface{}) {
	*pq = append(*pq, x.(CodeCnt))
}

func (pq *CodeCntMaxHeap) Pop() interface{} {
	n := len(*pq) - 1
	x := (*pq)[n]
	*pq = (*pq)[:n]
	return x
}

func (pq *CodeCntMaxHeap) Peek() CodeCnt {
	return (*pq)[0]
}

```