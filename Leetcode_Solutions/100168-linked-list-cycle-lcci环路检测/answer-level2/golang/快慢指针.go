### 解题思路

分两步：确定是否有环，若有环则进入另一个循环找到入环的第一个节点即可

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
    if head == nil || head.Next == nil {
        return nil
    }
    slow, fast := head, head
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
        if slow == fast {
            fast = head
            for slow != fast {
                slow, fast = slow.Next, fast.Next
            }
            return slow
        }
    }

    return nil
}
```