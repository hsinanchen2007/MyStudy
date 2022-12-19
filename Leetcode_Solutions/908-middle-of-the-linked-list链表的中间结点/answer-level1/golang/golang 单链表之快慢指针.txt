### 解题思路
快指针走两步，慢指针走一步，即可满足题设要求。
所以明确了往前走两步的条件（或者不能再走两步的条件）即可。

fast != nil && fast.Next != nil 即可走两步 fast = fast.Next.Next
fast == nil || fast.Next == nil 不能走两步

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
    fast, slow := head, head
    for {
        if fast == nil || fast.Next == nil {
            break
        }
        fast = fast.Next.Next
        slow = slow.Next
    }
    return slow
}
// 或者
func middleNode(head *ListNode) *ListNode {
    fast, slow := head, head
    for fast != nil && fast.Next != nil {
        fast = fast.Next.Next
        slow = slow.Next
    }
    return slow
}
```