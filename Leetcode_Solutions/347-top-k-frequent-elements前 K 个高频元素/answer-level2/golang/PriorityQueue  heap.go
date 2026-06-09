### 解题思路
此处撰写解题思路

### 代码

```golang
func topKFrequent(nums []int, k int) []int {
    items := make(map[int]int,0) 
    for i := range nums {
        items[nums[i]]++
    }
    pq := make(PriorityQueue, len(items))
    i := 0
    for k,v := range items {
        pq[i] = &Item{
            key:    k,
            rate:   v,
            index:    i,
        }
        i++
    }
    heap.Init(&pq)

    result := make([]int,0)
    i = 0
    for  i < k{
        item := heap.Pop(&pq).(*Item)
        result = append(result, item.key)
        i++
    }
    return result
}

type Item struct {
    key     int 
    rate    int
    index   int // The index of the item in the heap.
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
    // We want Pop to give us the highest, not lowest, priority so we use greater than here.
    return pq[i].rate > pq[j].rate
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