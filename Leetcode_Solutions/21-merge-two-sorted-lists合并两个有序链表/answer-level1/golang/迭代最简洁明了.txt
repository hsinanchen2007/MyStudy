### 解题思路
时间复杂度O(m+n)，空间复杂度O(1)

执行用时 :4 ms, 在所有 Go 提交中击败了69.55% 的用户
内存消耗 :2.5 MB, 在所有 Go 提交中击败了100.00%的用户

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{} //头结点
	cursor := head      //指针
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			cursor.Next = l1
			l1 = l1.Next
		} else {
			cursor.Next = l2
			l2 = l2.Next
		}
		cursor = cursor.Next
	}
	//任一条到达尾部，直接拼上另一条
	if l1 == nil {
		cursor.Next = l2
	} else {
		cursor.Next = l1
	}
	return head.Next
}
```