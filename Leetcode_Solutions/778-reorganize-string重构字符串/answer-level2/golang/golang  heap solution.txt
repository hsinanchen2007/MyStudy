```
func reorganizeString(s string) string {
	size := len(s)
	if size <= 1 {
		return s
	}
	res := make([]byte, 0)
	m := make(map[byte]int)

	for _, v := range s {
        m[byte(v)]++
	}

	h := &IntHeap{}
	heap.Init(h)

	for k, v := range m {
		if v > (size+1)/2 {
			return ""
		}
		heap.Push(h, Char{ch: k, count: v})
	}

	for h.Len() >= 2 {
		t1 := heap.Pop(h).(Char)
		t2 := heap.Pop(h).(Char)

		res = append(res, t1.ch, t2.ch)
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
		t := heap.Pop(h).(Char)
		res = append(res, t.ch)
	}
	return string(res)
}

type Char struct {
	ch    byte
	count int
}

// An IntHeap is a max-heap of ints.
type IntHeap []Char

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i].count > h[j].count }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(Char))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

```
