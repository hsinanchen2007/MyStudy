### 解题思路

设置快慢指针，快指针一次走两步，慢指针一次走一步，将其都设置为`head`，如果快指针在遍历的过程中遍历到链表尾部出去了，说明该链表无环，直接返回 `nil` 即可，
相反的是，如果两个指针相遇，则必存在环，然后break掉当前循环，让fast指针指向head指针，然后走一步，慢指针不变，也是走一步，当他们两个相遇的时候即是环的入口节点。

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
	if head == nil || head.Next == nil || head.Next.Next == nil {
		return nil
	}

	slow, fast := head.Next, head.Next.Next
	for {
		if fast.Next == nil || fast.Next.Next == nil {
			return nil
		}

		if fast == slow {
			break
		}

		slow = slow.Next
		fast = fast.Next.Next
	}

	fast = head
	for fast != slow {
		slow = slow.Next
		fast = fast.Next
	}
	return slow
}
```