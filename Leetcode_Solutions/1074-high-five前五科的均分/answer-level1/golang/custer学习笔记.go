```go
package main

import (
	"container/heap"
	"fmt"
	"sort"
)

func highFive(items [][]int) [][]int {
	val := make(map[int]*IntHeap)
	for i := 0; i < len(items); i++ {
		if _, ok := val[items[i][0]]; !ok {
			h := &IntHeap{}
			heap.Init(h)
			val[items[i][0]] = h
		}
		heap.Push(val[items[i][0]], items[i][1])
		if val[items[i][0]].Len() > 5 {
			heap.Pop(val[items[i][0]])
		}
	}
	ret := make([][]int, 0)
	for k, h := range val {
		score := 0
		for h.Len() > 0 {
			score += heap.Pop(h).(int)
		}
		ret = append(ret, []int{k, score / 5})
	}
	sort.Slice(ret, func(i, j int) bool {
		return ret[i][0] < ret[j][0]
	})
	return ret
}

type IntHeap []int

func (h IntHeap) Len() int            { return len(h) }
func (h IntHeap) Less(i, j int) bool  { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

//////////测试//////
func main() {
	arr := [][]int{{1, 91}, {1, 92}, {2, 93}, {2, 97}, {1, 60}, {2, 77}, {1, 65}, {1, 87}, {1, 100}, {2, 100}, {2, 76}}
	fmt.Println(highFive(arr))
}
```