```go
import "container/heap"

type KthLargest struct {
    q IntHeap
    k int
}


func Constructor(k int, nums []int) KthLargest {
    var q IntHeap
    for i, n := range nums {
        if i <= k-1 {
            heap.Push(&q, n)
        } else if (n > q[0]) {
            heap.Pop(&q)
            heap.Push(&q, n)
        }
    }
    return KthLargest{q, k}
}


func (this *KthLargest) Add(val int) int {
    if (len(this.q) < this.k) {
        heap.Push(&this.q, val)
    } else if (val > this.q[0]) {
        heap.Pop(&this.q)
        heap.Push(&this.q, val)
    }
    return this.q[0]
}


/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */

type IntHeap []int

func (h IntHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h IntHeap) Less(i, j int) bool {
    return h[i] < h[j]
}

func (h IntHeap) Len() int {
    return len(h)
}

func (h *IntHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
    n := len(*h)
    x := (*h)[n-1]
    *h = (*h)[:n-1]
    return x
}
```