```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
	var (
		fast, slow *ListNode
	)

	fast = head
	slow = head
	for fast != nil {
		fast = fast.Next
		if fast != nil {
			fast = fast.Next
		}
		slow = slow.Next
	}
	slow = reverseList(slow)
	for slow != nil {
		if slow.Val != head.Val {
			return false
		}
		slow = slow.Next
		head = head.Next
	}
	return true
}

func reverseList(head *ListNode) (newHead *ListNode) {
	for head != nil {
		tmp := head
		head = head.Next
		tmp.Next = newHead
		newHead = tmp
	}
	return
}

```
