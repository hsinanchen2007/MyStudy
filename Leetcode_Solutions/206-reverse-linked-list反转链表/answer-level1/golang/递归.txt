### 解题思路
递归

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
    if head == nil ||head.Next == nil {
		return head
	}
	tmpListNode := reverseList(head.Next)
	tmp := tmpListNode
	for tmp.Next != nil {
		tmp = tmp.Next
	}
	tmp.Next = head
	tmp.Next.Next = nil
	return tmpListNode

}
```