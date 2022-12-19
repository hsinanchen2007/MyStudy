```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type ListNodeHeap []*ListNode

func (lp *ListNodeHeap) Push(x interface{}) {
	*lp = append(*lp, x.(*ListNode))
}

func (lp *ListNodeHeap) Pop() interface{} {
	old := *lp
	n := len(old)
	x := old[n-1]
	*lp = old[0 : n-1]
	return x
}

func (lp ListNodeHeap) Len() int {
	return len(lp)
}

func (lp ListNodeHeap) Less(i, j int) bool {
	return lp[i].Val < lp[j].Val
}

func (lp ListNodeHeap) Swap(i, j int) {
	lp[i], lp[j] = lp[j], lp[i]
}

// 小顶堆
func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}

	lp := &ListNodeHeap{}
	for i := 0; i < len(lists); i++ {
		if lists[i] != nil {
			heap.Push(lp, lists[i])
		}
	}

	if lp.Len() == 0 {
		return nil
	}

	head := heap.Pop(lp).(*ListNode)
	cur := head
	nextToPush := cur.Next

	var next *ListNode
	for lp.Len() != 0 {
		if nextToPush != nil {
			heap.Push(lp, nextToPush)
		}
		next = heap.Pop(lp).(*ListNode)
		cur.Next = next
		cur = cur.Next
		nextToPush = next.Next
	}

	return head
}
```
