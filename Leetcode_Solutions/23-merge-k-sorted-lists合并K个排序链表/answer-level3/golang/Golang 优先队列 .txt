
- 将当前所有单链表头部元素构建成优先队列，该优先队列的最小值为全局最小值
- 取出该最小值，从最小值所属队列取出它的后继重新加入优先队列
- 重复如上操作，直到队列不包含任何元素

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type PQ []*ListNode 

func (p PQ) Len() int { return len(p) }
func (p PQ) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
}
func (p PQ) Less(i, j int) bool {
    return p[i].Val < p[j].Val
}

func (p *PQ) Push(x interface{}) {
	node := x.(*ListNode)
	*p = append(*p, node)
}

func (p *PQ) Pop() interface{} {
	old := *p
	n := len(old)
	item := old[n-1]
	*p = old[0 : n-1]
	return item
}

func mergeKLists(lists []*ListNode) *ListNode {
    h := &ListNode {
        Val: -1,
        Next: nil,
    }
    t := h
    if len(lists) == 0 {
        return h.Next
    }
    
    pq := make(PQ, 0)
    for i, _ := range lists {
        if lists[i] != nil {
            pq = append(pq, lists[i])
        }
    }
    heap.Init(&pq)
    
    for len(pq) > 0 {
        item := heap.Pop(&pq).(*ListNode)
        next := item.Next
        
        item.Next = t.Next
        t.Next = item
        t = item
        
        if next != nil {
            heap.Push(&pq, next)
        }
    }
    
    return h.Next
    
}
```