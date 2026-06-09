### 解题思路
链表的基本操作

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
	if head == nil || head.Next == nil {
		return head
	}
	var rev *ListNode
	for head != nil {
		next := head.Next // 保存原链表头节点的后继节点
		head.Next = rev   // 原链表头节点插入到反转链表首部
		rev = head        // 反转链表头节点指针指向新首部
		head = next       // 原链表头节点指针指向其保存的后继节点
	}
	return rev
}
```