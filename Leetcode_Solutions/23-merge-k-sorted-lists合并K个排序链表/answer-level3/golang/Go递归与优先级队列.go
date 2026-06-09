1. 优先级队列
```
type PriorityQueue []*ListNode 
func (p PriorityQueue) Len() int { return len(p) }
func (p PriorityQueue) Swap(i, j int) { p[i], p[j] = p[j], p[i]}
func (p PriorityQueue) Less(i, j int) bool { return p[i].Val < p[j].Val }
func (p *PriorityQueue) Push(x interface{}) { *p = append(*p, x.(*ListNode)) }
func (p *PriorityQueue) Pop() interface{} {
    x := (*p)[len(*p) - 1];
    *p = (*p)[:len(*p) - 1]
	return x
}

func mergeKLists(lists []*ListNode) *ListNode {
    if len(lists) == 0 {
        return nil
    }
    pq := make(PriorityQueue, 0)
    for i, _ := range lists {
        if lists[i] != nil {
            pq = append(pq, lists[i])
        }
    }
    heap.Init(&pq)
    h := &ListNode {
        Val: -1,
        Next: nil,
    }
    t := h
    for len(pq) > 0 {
        minList := heap.Pop(&pq).(*ListNode)
        t.Next = minList
        minList = minList.Next
        t = t.Next
        if minList != nil {
            heap.Push(&pq, minList)
        }
    }
    return h.Next
}
```

1. 递归

```
func mergeKLists(lists []*ListNode) *ListNode {
    for i := 0 ; i < len(lists); i++ {
        if  nil == lists[i] {
            lists = append(lists[:i], lists[i+1:]...)
            i--
        }
    }
    if 0 == len(lists) {
        return nil
    }
    minIdx, minVal := 0, lists[0].Val
    for i :=0 ; i < len(lists); i++ {
        if minVal > lists[i].Val {
            minVal = lists[i].Val
            minIdx = i
        }
    }
    var res * ListNode
    res = lists[minIdx]
    lists[minIdx] = lists[minIdx].Next
    res.Next = mergeKLists(lists)
    return res
}
```
