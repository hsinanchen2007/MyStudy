golang实现，快慢双指针 + 虚拟头结点．

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 快慢双指针 + 虚拟头结点
// 通过建立虚拟头结点，可以将原链表头结点当做非头结点处理，避免额外考虑待删除节点为原链表头结点的情况
// 时间复杂度：O(n)  空间复杂度：O(1)
 
 func removeNthFromEnd(head *ListNode, n int) *ListNode {

	// 虚拟头结点
	dummy_head := &ListNode{}  
	dummy_head.Next = head

	// 快慢双指针
	fast := dummy_head
	slow := dummy_head

	for i:=0; i<n; i++ {
		if fast==nil {  // 处理 "len(head)<n" 的情况
			return nil
		}
		fast = fast.Next
	}

	for fast.Next!=nil {
		fast = fast.Next
		slow = slow.Next
	}

	// 此时的"slow"为待删除节点的前驱节点
	temp := slow.Next
	slow.Next = slow.Next.Next
	temp.Next = nil

	return dummy_head.Next
}
```
