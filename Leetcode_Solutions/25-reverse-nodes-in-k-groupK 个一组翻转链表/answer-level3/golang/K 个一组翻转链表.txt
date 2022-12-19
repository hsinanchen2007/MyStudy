### 解题思路
翻转子链表

### 代码

```golang
func reverseKGroup(head *ListNode, k int) *ListNode {
	if k <= 0 {
		return head
	}
	n, p := 0, head
	for p != nil {
		p = p.Next
		n++
	}
	num := n / k
	h, childHead := &ListNode{}, head
	p = h
	for i := 0; i < num; i++ {
		var nextCh *ListNode
		p.Next, nextCh = reverseK(childHead, k)
		// 将p指向翻转后的尾部
		p = childHead
		// 将next指向下一子链表的开头
		childHead = nextCh
	}
	p.Next = childHead
	return h.Next
}

func reverseK(head *ListNode, k int) (*ListNode, *ListNode) {
	var (
		next, prev, curr *ListNode
	)
	curr = head
	for k > 0  {
		next = curr.Next
		curr.Next = prev
		prev = curr
		curr = next
		k--
	}
	// 返回翻转后子链表的首节点和下一子链表的起始子节点
	return prev, curr
}

```