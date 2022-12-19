```go
import (
    "container/heap"
)

type MaxHeap []int
type MinHeap []int

func (h MaxHeap) Len() int { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *MaxHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}
func (h *MaxHeap) Pop() interface{} {
    old := *h
    n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h MinHeap) Len() int { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h MinHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *MinHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}
func (h *MinHeap) Pop() interface{} {
    old := *h
    n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type MedianFinder struct {
    lower MaxHeap
    upper MinHeap
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
    return MedianFinder{make([]int, 0), make([]int, 0)}
}

func (this *MedianFinder) AddNum(num int)  { // len(lower) >= len(upper)
    if len(this.lower) == 0 || this.lower[0] >= num {
        heap.Push(&this.lower, num)
    } else {
        heap.Push(&this.upper, num)
    }
    
    if len(this.upper) > len(this.lower) {
        v := heap.Pop(&this.upper)
        heap.Push(&this.lower, v)
    } else if len(this.lower) > len(this.upper) + 1 {
        v := heap.Pop(&this.lower)
        heap.Push(&this.upper, v)
    }
}

func (this *MedianFinder) FindMedian() float64 {
    if len(this.lower) > len(this.upper) {
        return float64(this.lower[0])
    } else {
        return float64(this.lower[0] + this.upper[0]) / 2.0
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */
```

内存占用挺高，后期看下如何优化
