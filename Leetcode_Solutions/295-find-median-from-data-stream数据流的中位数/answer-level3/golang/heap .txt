### 解题思路
此处撰写解题思路

### 代码

```golang
type MedianFinder struct {
    p1 *IntHeap     // 顶部最大
    p2 *IntHeaps    // 顶部最小
}


/** initialize your data structure here. */
func Constructor() MedianFinder {
    h1 := &IntHeap{}
    heap.Init(h1)
    h2 := &IntHeaps{}
    heap.Init(h2)

    return MedianFinder{
        p1: h1,
        p2: h2,
    }
}


func (this *MedianFinder) AddNum(num int)  {
    heap.Push(this.p1, num)
    a := heap.Pop(this.p1)
    heap.Push(this.p2, a)

    if this.p2.Len() > this.p1.Len() {
        a = heap.Pop(this.p2) 
        heap.Push(this.p1, a)
    }
}


func (this *MedianFinder) FindMedian() float64 {
   if this.p2.Len() == this.p1.Len() {
       return float64((*this.p1)[0] + (*this.p2)[0]) / 2
   }else {  
        return float64((*this.p1)[0] )
   }
}


// 顶部最大
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
    // Push and Pop use pointer receivers because they modify the slice's length,
    // not just its contents.
    *h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

// 顶部最小
type IntHeaps []int

func (h IntHeaps) Len() int           { return len(h) }
func (h IntHeaps) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeaps) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeaps) Push(x interface{}) {
    // Push and Pop use pointer receivers because they modify the slice's length,
    // not just its contents.
    *h = append(*h, x.(int))
}

func (h *IntHeaps) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

/*
    h := &IntHeap{2, 1, 5}
    heap.Init(h)
    heap.Push(h, 3)
    fmt.Printf("minimum: %d\n", (*h)[0])
    for h.Len() > 0 {
        fmt.Printf("%d ", heap.Pop(h))
    }
*/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */
```