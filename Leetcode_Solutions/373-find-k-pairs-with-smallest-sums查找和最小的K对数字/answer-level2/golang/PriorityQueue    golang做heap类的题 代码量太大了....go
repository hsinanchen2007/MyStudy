### 解题思路

type Item struct {
    value    []int  // 记录数组对
    priority int    //  记录数组对之和， 用于堆排序
    index int 
}

### 代码

```golang
func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
    length1, length2 := len(nums1), len(nums2)
    var count int
    pq := make(PriorityQueue, length1*length2)
    for i := 0; i < length1; i++ {
        for j :=0; j < length2; j++ {
            value := []int{nums1[i],nums2[j]} 
            priority := nums1[i] + nums2[j]
            pq[count] = &Item{
                value: value,
                priority:   priority,
                index:  count,
            }
            count++
        }
    }
    result := make([][]int,0)
    heap.Init(&pq)
    if k == 0 || pq.Len() == 0 {
        return result
    }
    if k > pq.Len() {
        k = pq.Len()
    }
    
    for i :=0; i < k; i++ {
        item := heap.Pop(&pq).(*Item)
        result = append(result, item.value)
    }
    return result
}

type Item struct {
    value    []int // The value of the item; arbitrary.
    priority int    // The priority of the item in the queue.
    // The index is needed by update and is maintained by the heap.Interface methods.
    index int // The index of the item in the heap.
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
    // We want Pop to give us the highest, not lowest, priority so we use greater than here.
    return pq[i].priority < pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
    pq[i].index = i
    pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
    n := len(*pq)
    item := x.(*Item)
    item.index = n
    *pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
    old := *pq
    n := len(old)
    item := old[n-1]
    old[n-1] = nil  // avoid memory leak
    item.index = -1 // for safety
    *pq = old[0 : n-1]
    return item
}
```