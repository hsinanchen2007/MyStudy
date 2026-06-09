### 解题思路
翻转后半部分子链表,再与前半部分子链表比对.

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}
	if head.Next.Next == nil {
		return head.Val == head.Next.Val
	}
	fast := head
	slow := head
	for fast.Next != nil && fast.Next.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}
	next := slow.Next
	slow.Next = nil
	reversed := reverse(next)
	for reversed != nil {
		if reversed.Val != head.Val {
			return false
		}
		reversed = reversed.Next
		head = head.Next
	}
	return true
}

func reverse(head *ListNode) *ListNode {
	var (
		next, prev, curr *ListNode
	)
	curr = head
	for curr != nil {
		next = curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}
	return prev
}

```