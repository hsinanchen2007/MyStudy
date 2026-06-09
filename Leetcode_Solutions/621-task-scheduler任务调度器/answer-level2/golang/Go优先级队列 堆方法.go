//https://golang.org/pkg/container/heap/

```
type IntHeap []int
func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func leastInterval(tasks []byte, n int) int {
    m := make(map[byte]int)
    for _, v := range(tasks) {
        m[v]++
    }
    h := &IntHeap{}
    heap.Init(h)
    for _, v := range(m) {
        heap.Push(h, v)
    }
    res := 0
    circle := n + 1
    for h.Len() > 0 {
        vector := []int{}
        cnt := 0
        for i:=0; i < circle; i++ {
            if h.Len() > 0 {
                vector = append(vector, heap.Pop(h).(int))
                cnt++    
            }
        }
        for _,d := range(vector) {
            if d > 1 {
                heap.Push(h, d-1)
            }
        }
        if h.Len() > 0 {
            res += circle
        } else {
            res += cnt
        }
        //fmt.Println(res)
    }
    return res
    
}
```
