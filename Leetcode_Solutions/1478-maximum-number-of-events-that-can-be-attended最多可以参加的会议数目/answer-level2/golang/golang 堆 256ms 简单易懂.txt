其实就是每次把，最早开始的拿出来。如果结束时间比当前时间晚，开始时间+1 放到堆中继续
```
func maxEvents(events [][]int) int {
    h := &IntHeap{}
    heap.Init(h)
    for i := 0; i < len(events); i++ {
        heap.Push(h, events[i])
    }
    now := 1
    ret := 0
    for h.Len() > 0 {
        t := heap.Pop(h).([]int)
        if t[1] < now {
            continue
        }
        if t[0] >= now || t[0] == t[1] {
            ret++
            now = t[0] + 1
            continue
        }
        t[0] = now
        heap.Push(h, t)
    }
    return ret
}

type IntHeap [][]int

func (h IntHeap) Len() int           { return len(h) }

func (h IntHeap) Less(i, j int) bool { 
    if h[i][0] == h[j][0] {
        return h[i][1] < h[j][1] 
    }
    return h[i][0] < h[j][0]
}
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.([]int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
```
