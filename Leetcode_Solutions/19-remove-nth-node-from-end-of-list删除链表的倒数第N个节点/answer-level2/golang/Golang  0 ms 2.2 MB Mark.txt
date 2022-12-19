
维护双指针， 记得处理恰好需要删除头节点的情况
```
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	node := head // 前指针
	node2 := node // 后指针, 指向应被删除的节点的前一个节点
	diff := 0 // 前后指针之间的差距
	// 找到删除点
	for node.Next != nil {
		if diff < n { // 前指针移动步数小于n, 后指针未开始移动
			node = node.Next
			diff++
		} else {
			node = node.Next
			node2 = node2.Next
		}
	}
	if diff == n { // 删除中间或结尾节点
		node2.Next = node2.Next.Next
		return head
	} else if diff == n - 1 { // 恰好需要删除头指针
		return head.Next
	} else { // n > len, 异常输入
		return nil
	}
}
```
