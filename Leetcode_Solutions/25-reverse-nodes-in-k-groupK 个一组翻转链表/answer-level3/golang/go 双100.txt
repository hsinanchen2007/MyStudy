### 解题思路
此处撰写解题思路

### 代码

```golang
func reverseKGroup(head *ListNode, k int) *ListNode {
	var dummy ListNode
	dummy.Next = head
	pre, start, end := &dummy, &dummy, &dummy
	for end != nil {
		start = pre.Next
		for i := 0; i < k; i++ {
			end = end.Next
			if end == nil{
				return dummy.Next
			}
		}
		next := end.Next
		end.Next = nil
		pre.Next = reverse(start)
		pre, end = start, start
		start.Next = next
	}
	return dummy.Next
}

func reverse(head *ListNode) *ListNode {
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