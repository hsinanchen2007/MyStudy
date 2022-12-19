### 解题思路

快慢指针，然后遍历，直到`fast.Next == nil` 或者 `fast.Next.Next == nil` 不满足。
则退出循环，然后判断`fast.Next` 是否为空，若为空，则表明有奇数节点，此时直接返回`slow`指针指向的
节点即可，否则返回`slow.Next`.

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func middleNode(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	slow, fast := head, head
	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	if fast.Next != nil {
		return slow.Next
	}else {
		return slow
	}
}
```