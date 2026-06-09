
直译了一把题解二。。。大佬写的真牛批，通俗易懂
```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
var nextN *ListNode = nil

func reverseN(head *ListNode,  n int) *ListNode {
	if n == 1 {
		nextN = head.Next
		return head
	}
	lastNode := reverseN(head.Next, n-1)
	head.Next.Next = head
	head.Next = nextN
	return lastNode
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	if m == 1 {
		return  reverseN(head, n)
	}
	head.Next = reverseBetween(head.Next, m-1, n-1)
	return head
}
```
