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
func hasCycle(head *ListNode) bool {
    slow := head
    quick := head

    for slow != nil && quick != nil {
        quick = quick.Next
        if quick == nil {
            return false
        }
        if quick == slow {
            return true
        }
        slow = slow.Next
        quick = quick.Next
        if slow == quick {
            return true
        }
    }
    return false
}
```