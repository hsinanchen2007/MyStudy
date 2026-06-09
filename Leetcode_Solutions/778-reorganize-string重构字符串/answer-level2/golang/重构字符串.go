### 解题思路
计数, 最大堆

### 代码

```golang
//	767
func reorganizeString(S string) string {
	cntMap := make(map[rune]int)
	for _, r := range S {
		cntMap[r]++
	}
	var lastRc RuneCnt
	minHeap := &RuneCntMaxHeap{}
	for k, v := range cntMap {
		heap.Push(minHeap, RuneCnt{
			run: k,
			cnt: v,
		})
	}
	runes := make([]rune, 0, len(S))
	for minHeap.Len() > 0 {
		
		temp := heap.Pop(minHeap).(RuneCnt)
		if temp.run == lastRc.run {
			break
		}
		runes = append(runes, temp.run)
		temp.cnt--
		if lastRc.cnt > 0 {
			heap.Push(minHeap, lastRc)
		}
		lastRc = temp
	}
	if len(runes) == len(S) {
		return string(runes)
	}
	return ""	
}

type RuneCnt struct {
	run rune
	cnt int
}

type RuneCntMaxHeap []RuneCnt

func (pq *RuneCntMaxHeap) Len() int {
	return len(*pq)
}
func (pq *RuneCntMaxHeap) Less(i, j int) bool {
	return (*pq)[i].cnt > (*pq)[j].cnt
}
func (pq *RuneCntMaxHeap) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *RuneCntMaxHeap) Push(x interface{}) {
	*pq = append(*pq, x.(RuneCnt))
}

func (pq *RuneCntMaxHeap) Pop() interface{} {
	n := len(*pq) - 1
	x := (*pq)[n]
	*pq = (*pq)[:n]
	return x
}
func (pq *RuneCntMaxHeap) Peek() RuneCnt {
	return (*pq)[0]
}

```