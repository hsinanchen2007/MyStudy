### 解题思路
此处撰写解题思路

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
     // 为空或者只有一个节点的情况排除
    if head == nil || head.Next == nil {
        return true
    }
    // 慢指针
	var slow *ListNode = head
    // 快指针
	var fast *ListNode = head
    // 记忆节点，用于在节点操作当前节点时保存节点的下一跳
	var temp *ListNode = nil
	var prev *ListNode = nil
    // 找到中间节点，同时将慢指针操作的前半部分节点反转
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		temp = slow.Next
		slow.Next = prev
		prev = slow
		slow = temp
	}
    // 如果快指针不为空，说明此链表是奇数节点，所以需要跳过中间值
	if fast !=nil {
        slow = slow.Next
    }
    // l1是前半部分节点
	var l1 *ListNode = prev
    // l2是后半部分节点
	var l2 *ListNode = slow
	for l1 != nil && l2 != nil && l1.Val == l2.Val {
		l1 = l1.Next
		l2 = l2.Next
	}
	return l1 == nil && l2 == nil
}
```