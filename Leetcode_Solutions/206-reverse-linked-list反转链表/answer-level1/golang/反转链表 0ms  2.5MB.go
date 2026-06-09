### 解题思路
设置 3 个指针，当前元素current，上一个元素left（初始为空），下一个元素right。如果right不为空则一直迭代，right为空时直接将current的下一个设置为left即可，最后返回current即可。

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
    // 特殊情况处理
	if head == nil || head.Next == nil {
		return head
	}
	// 迭代
	var left *ListNode
	current := head
	right := current.Next
	for right != nil {
		current.Next = left
		left = current
		current = right
		right = right.Next
	}
	current.Next = left
	return current
}
```