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
func swapPairs(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	var h *ListNode = &ListNode{}
	prev := h
	prev.Next = head

	p := head
	n := p.Next
	for n != nil {
		np := n.Next

		// 交换相邻节点
		prev.Next = n
		n.Next = p
		p.Next = np

		// 修改前缀指针prev
		prev = p

		// 递进p,n
		p = np
		if np != nil {
			n = np.Next
		} else {
			n = nil
		}
	}
	return h.Next
}
```