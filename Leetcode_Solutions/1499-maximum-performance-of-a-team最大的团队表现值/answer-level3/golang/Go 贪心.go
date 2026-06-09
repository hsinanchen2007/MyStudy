```
import (
    "container/heap"
    "sort"
)

type Item struct {
    index      int
    speed      int
    efficiency int
}

func maxPerformance(n int, speed []int, efficiency []int, k int) int {
    var (
        i, sum  int
        objs    = make([]*Item, n)
        tmpSum  int64
        newHeap = minHeap(make([]int, 0))
    )
    for i = 0; i < n; i++ {
        objs[i] = &Item{
            index:      i,
            efficiency: efficiency[i],
            speed:      speed[i],
        }
    }
    sort.Slice(objs, func(i, j int) bool {
        return objs[i].efficiency > objs[j].efficiency
    })

    heap.Init(&newHeap)
    for i = 0; i < n; i++ {
        heap.Push(&newHeap, objs[i].speed)
        sum += objs[i].speed
        if len(newHeap) > k {
            sum -= heap.Pop(&newHeap).(int)
        }
        currSum := int64(sum) * int64(objs[i].efficiency)
        if currSum > tmpSum {
            tmpSum = currSum
        }
    }
    return int(tmpSum % 1000000007)
}

type minHeap []int

func (h minHeap) Len() int           { return len(h) }
func (h minHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h minHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *minHeap) Push(x interface{}) {
    // Push and Pop use pointer receivers because they modify the slice's length,
    // not just its contents.
    *h = append(*h, x.(int))
}

func (h *minHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}
```
