### 解题思路
经典解法

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
	var next *ListNode = nil
	var prev *ListNode = nil
	curr := head
	for curr != nil {
		next = curr.Next
		curr.Next = prev
		
		prev = curr
		curr = next
	}
	return prev
}
```