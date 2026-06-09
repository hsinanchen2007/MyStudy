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
    lo, hi := head, head
    for hi != nil && hi.Next != nil {
        lo = lo.Next
        hi = hi.Next.Next

    }
    return lo
    
}
```