### 解题思路
交换链表中的节点，主要思路基本一致，就是两点：
1. 使用一个指针指向新反转的链表中的某个位置（pre），不断在这个位置更新指针的next
2. 使用一个指针指向输入的链表头（head），不断进行相应的操作（反转），然后将head指向后续的位置
3. 这一步很重要，就是最后更新pre的next，防止出现循环

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	// 特殊情况判断
    if head == nil || head.Next == nil {
		return head
	}

	// 保留结果指针
	result := head.Next

	// 两两交换
	var pre *ListNode
	for head != nil && head.Next != nil {
		// 更新pre链表，一个是next指针，一个是指向新的位置
		if pre != nil {
			pre.Next = head.Next
		}
		pre = head

		// 反转
		next := head.Next
		next2 := next.Next
		next.Next = head
		head = next2
	}

	// 最后更新下pre链表的next，要么是空，要么是最后的一个指针
	pre.Next = head
	return result
}
```

时间复杂度为O(n)