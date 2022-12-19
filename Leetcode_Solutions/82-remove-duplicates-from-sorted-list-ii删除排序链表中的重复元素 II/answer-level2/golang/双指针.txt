### 解题思路
双指针

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	var p *ListNode = &ListNode{}
	h := p
	p.Next = head
	var node *ListNode = head
	for node != nil {
		val := node.Val
		dup := false
		for node.Next != nil && node.Next.Val == val {
			node = node.Next
			dup = true
		}
		if dup {
			p.Next = node.Next
		}else {
			p = p.Next
		}
		node = node.Next
	}
	return h.Next
}

```