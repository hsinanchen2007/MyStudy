### 解题思路
主要的逻辑：保存后续节点->变更指针指向->节点替换

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
	var pre *ListNode
	cur := head
	var next *ListNode

	for cur != nil {
		next = cur.Next

		cur.Next = pre

		pre = cur
		cur = next
	}
	return pre
}
```