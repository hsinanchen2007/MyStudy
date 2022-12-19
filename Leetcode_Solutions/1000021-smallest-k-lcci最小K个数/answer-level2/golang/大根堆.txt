```go
import (
	"container/heap"
	"sort"
)

type IntHeap []int


func(h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h IntHeap) Top() int {
	return h[0]
}

func(h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func(h IntHeap) Len() int {
	return len(h)
}

func(h IntHeap) Less(i, j int) bool {
	return h[i] > h[j]
}

func smallestK(arr []int, k int) []int {
    if k == 0 {
        return nil
    }
	h := new(IntHeap)
	heap.Init(h)

	for _, ar := range arr {
		if h.Len() < k {
			heap.Push(h, ar)
		} else {
			top := h.Top()
            //fmt.Println(top, ar, h)
			if top > ar {
				heap.Pop(h)
				heap.Push(h, ar)
			}
		}
	}
	sort.Ints([]int(*h))
	return []int(*h)
}

```