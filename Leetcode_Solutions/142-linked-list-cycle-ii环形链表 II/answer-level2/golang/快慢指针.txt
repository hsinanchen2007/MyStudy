### 解题思路
快慢指针

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
	fast := head
	slow := head
	hasCyc := false
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
		if fast == slow {
			hasCyc = true
			break
		}
	}
	if !hasCyc {
		return nil
	}
	slow = head
	for fast != slow {
		slow = slow.Next
		fast = fast.Next
	}
	return fast
}
```