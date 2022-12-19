
```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    p := head.Next
	if p == nil {
		return head
	}
	
	head.Next = nil
	q := head
	
	for p != nil  {
		next := p.Next
		p.Next = q
		q = p
		p = next
	}
	return q
}
```
