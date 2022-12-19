```
func rearrangeBarcodes(barcodes []int) []int {
	return rearrangeBarcodesHelper(barcodes)
}

func rearrangeBarcodesHelper(s []int) []int {
	size := len(s)
	if size <= 1 {
		return s
	}
	res := make([]int, 0)
	m := make(map[int]int)

	for _, v := range s {
		m[v]++
	}

	h := &IntHeap{}
	heap.Init(h)

	for k, v := range m {
		if v > (size+1)/2 {
			return nil
		}
		heap.Push(h, Point{val: k, count: v})
	}

	for h.Len() >= 2 {
		t1 := heap.Pop(h).(Point)
		t2 := heap.Pop(h).(Point)

		res = append(res, t1.val, t2.val)
		t1.count--
		t2.count--

		if t1.count > 0 {
			heap.Push(h, t1)
		}
		if t2.count > 0 {
			heap.Push(h, t2)
		}
	}
	if h.Len() > 0 {
		t := heap.Pop(h).(Point)
		res = append(res, t.val)
	}
	return (res)
}

type Point struct {
	val   int
	count int
}

// An IntHeap is a max-heap of ints.
type IntHeap []Point

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i].count > h[j].count }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(Point))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

```
