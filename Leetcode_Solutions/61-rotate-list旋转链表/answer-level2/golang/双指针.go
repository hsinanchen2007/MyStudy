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
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || k == 0 {
		return head
	}
	var prev *ListNode = &ListNode{}
	prev.Next = head
	var tail *ListNode = head
	var num int = 0
	for tail!=nil {
		num++
		tail = tail.Next
	}

	k = k%num
	if k == 0 {
		return head
	}
	k--
	tail = head
	for k > 0 {
		k--
		tail = tail.Next
	}
	for tail.Next!=nil {
		tail = tail.Next
		prev = prev.Next
	}
	h := prev.Next
	prev.Next = nil
	tail.Next = head
	return h
}

```