
	例：head = 1 -> 2 -> 3 -> 4 -> 5
1、获取中点指针
	中点应该是第 (n+1)/2 个节点, slow = 3
2、将原链表切分成两部分
	切分后：node1 = 1 -> 2 -> 3, node2 = 4 -> 5
3、反转node2
	反转后：node1 = 1 -> 2 -> 3, node2 = 5 -> 4
4、合并两个链表, 根据题意node1肯定至少和node2长度一样
	合并后: head = 1 -> 5 -> 2 -> 4 -> 3

```
func reorderList(head *ListNode) {
	if head == nil {
		return
	}
	var fast, slow *ListNode
	fast, slow = head, head
	//获取中点指针
	for fast != nil {
		fast = fast.Next
		if fast == nil {
			break
		}
		fast = fast.Next
		slow = slow.Next
	}
	//将原链表切分成node1, node2
	node2 := slow.Next
	slow.Next = nil
	//反转node2
	node2 = Reverse(node2)
	//合并两个链表
	for node1 := head; ; {
		if node2 == nil {
			break
		}
		next := node1.Next
		node1.Next = node2
		node2 = node2.Next
		node1.Next.Next = next
		node1 = node1.Next.Next
	}
}
func Reverse(head *ListNode) *ListNode {
	var pre *ListNode
	cur := head
	for cur != nil {
		next := cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}
	return pre
}

```
