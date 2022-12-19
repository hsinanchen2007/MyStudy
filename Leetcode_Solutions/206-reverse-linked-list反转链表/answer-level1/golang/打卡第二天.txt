### 解题思路
反转链表 第一个指向空 最后一个指向前一个即可

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    var tail, next *ListNode
	for head != nil && head.Next != nil {
		next = head.Next
		head.Next = tail
		tail = head
		head = next
	}
	if head != nil {
		head.Next = tail
	}
	return head
}
```