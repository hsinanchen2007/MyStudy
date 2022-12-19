和 767 差不多的思路

```go
import (
    "container/heap"
)

var counter map[int]int
type MaxHeap []int

func (h MaxHeap) Len() int { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return counter[h[i]] > counter[h[j]] }
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

func rearrangeBarcodes(barcodes []int) []int {
    counter = make(map[int]int)
    
    for i := 0; i < len(barcodes); i ++ {
        if v, ok := counter[barcodes[i]]; !ok {
            counter[barcodes[i]] = 1
        } else {
            counter[barcodes[i]] = v + 1
        }
    }
    
    keys := make(MaxHeap, 0)
    for k, _ := range counter {
        heap.Push(&keys, k)
    }
    n := len(keys)
    
    result := []int{}
    
    for len(counter) > 1 {
        largest := heap.Pop(&keys)
        second := heap.Pop(&keys)
        result = append(result, largest.(int), second.(int))
        
        counter[largest.(int)] -= 1
        if counter[largest.(int)] == 0 {
            delete(counter, largest.(int))
            n -= 1
        } else {
            heap.Push(&keys, largest)
        }
        
        counter[second.(int)] -= 1
        if counter[second.(int)] == 0 {
            delete(counter, second.(int))
            n -= 1
        } else {
            heap.Push(&keys, second)
        }
    }
    
    if n == 0 {
        return result
    } else {
        if counter[keys[0]] > 1 {
            return []int{}
        } else {
            result = append(result, keys[0])
            return result
        }
    }
}
```