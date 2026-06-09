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
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	h := head
	t := head
	for n > 0 {
		t = t.Next
		n--
	}
	
	// 删除第一个
	if t == nil {
		return head.Next
	}
	
	for t != nil && t.Next != nil {
		t = t.Next
		h = h.Next
	}

	h.Next = h.Next.Next
	return head
}


```