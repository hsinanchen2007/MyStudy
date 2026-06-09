```go
type IntHeap []int

func (h IntHeap) Len() int {return len(h)}
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j]}
func (h IntHeap) Swap(i,j int) {h[i], h[j] = h[j], h[i]}

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h 
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}

type IntHeapDesc []int

func (h IntHeapDesc) Len() int {return len(h)}
func (h IntHeapDesc) Less(i, j int) bool { return h[i] > h[j]}
func (h IntHeapDesc) Swap(i,j int) {h[i], h[j] = h[j], h[i]}

func (h *IntHeapDesc) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeapDesc) Pop() interface{} {
	old := *h 
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}


type MedianFinder struct {
	lo IntHeapDesc
	hi IntHeap
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
	a:= IntHeapDesc{}
	heap.Init(&a)
	b:= IntHeap{}
	heap.Init(&b)
	return MedianFinder{a,b}
    
}


func (this *MedianFinder) AddNum(num int)  {
	heap.Push(&this.lo, num)

	heap.Push(&this.hi, this.lo[0])
	heap.Pop(&this.lo)

	if len(this.lo) < len(this.hi) {
		heap.Push(&this.lo, this.hi[0])
		heap.Pop(&this.hi)
	}
}


func (this *MedianFinder) FindMedian() float64 {
	if len(this.lo) > len(this.hi)  {
		return float64(this.lo[0])
	}  else {
		return  float64((this.lo)[0] + (this.hi)[0])/2
	}
}
```
