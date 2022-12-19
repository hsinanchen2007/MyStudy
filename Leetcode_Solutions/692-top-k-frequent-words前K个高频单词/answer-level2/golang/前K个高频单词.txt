### 解题思路
最小堆

### 代码

```golang

//	692
func topKFrequent(words []string, k int) []string {
	cntMap := make(map[string]int, 0)
	for _, word := range words {
		cntMap[word]++
	}
	maxHeap := &WordCntMinHeap{}

	for key, val := range cntMap {
		heap.Push(maxHeap, WordCnt{
			word: key,
			cnt:  val,
		})
		if maxHeap.Len() > k {
			heap.Pop(maxHeap)
		}
	}
	res := make([]string, k)
	i := k-1
	for maxHeap.Len() > 0 {
		res[i] = heap.Pop(maxHeap).(WordCnt).word
		i--
	}
	return res
}

type WordCnt struct {
	word string
	cnt  int
}

type WordCntMinHeap []WordCnt

func (pq *WordCntMinHeap) Len() int {
	return len(*pq)
}
func (pq *WordCntMinHeap) Less(i, j int) bool {
	if (*pq)[i].cnt == (*pq)[j].cnt {
		return (*pq)[i].word > (*pq)[j].word
	}
	return (*pq)[i].cnt < (*pq)[j].cnt
}
func (pq *WordCntMinHeap) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *WordCntMinHeap) Push(x interface{}) {
	*pq = append(*pq, x.(WordCnt))
}

func (pq *WordCntMinHeap) Pop() interface{} {
	n := len(*pq) - 1
	x := (*pq)[n]
	*pq = (*pq)[:n]
	return x
}
func (pq *WordCntMinHeap) Peek() WordCnt {
	return (*pq)[0]
}

```