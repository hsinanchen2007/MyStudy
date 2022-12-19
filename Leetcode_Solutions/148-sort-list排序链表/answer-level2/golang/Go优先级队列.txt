时间复杂度O(nlogn)，空间复杂度O(n)
```
//https://golang.google.cn/pkg/container/heap
type PriorityQueue []int 
func (p PriorityQueue) Len() int { return len(p) }
func (p PriorityQueue) Swap(i, j int) { p[i], p[j] = p[j], p[i]}
func (p PriorityQueue) Less(i, j int) bool { return p[i] < p[j] }
func (p *PriorityQueue) Push(x interface{}) { *p = append(*p, x.(int)) }
func (p *PriorityQueue) Pop() interface{} {
    x := (*p)[len(*p) - 1];
    *p = (*p)[:len(*p) - 1]
	return x
}
func sortList(head *ListNode) *ListNode {
    if nil == head {
        return nil
    }
    pq := make(PriorityQueue, 0)
    for nil != head {
        pq = append(pq, head.Val)
        head = head.Next
    }
    heap.Init(&pq)
    h := &ListNode {
        Val: -1,
        Next: nil,
    }
    t := h
    for len(pq) > 0 {
        min := heap.Pop(&pq).(int)
        t.Next = &ListNode {
                Val: min,
                Next: nil,
            }
        t = t.Next
    }
    return h.Next
}
```
