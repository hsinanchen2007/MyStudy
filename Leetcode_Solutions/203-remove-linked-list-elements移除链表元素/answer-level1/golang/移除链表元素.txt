### 解题思路
遍历

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
	h := &ListNode{}
	h.Next = head
	p := h
	for p!=nil && p.Next!=nil {
		if p.Next.Val == val {
			p.Next = p.Next.Next
		} else {
            p = p.Next
        }

	}
	return h.Next
}
```