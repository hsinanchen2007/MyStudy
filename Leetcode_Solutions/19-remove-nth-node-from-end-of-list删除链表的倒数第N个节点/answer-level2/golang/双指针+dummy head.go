### 解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    var dummy = &ListNode{}
    dummy.Next = head
    var prev, cur *ListNode = dummy, dummy
    for i := 0; i < n; i++ {
        cur = cur.Next
        if cur == nil {
            return dummy.Next
        }
    }
    for cur != nil && cur.Next != nil {
        prev, cur = prev.Next, cur.Next
    }
    if prev != nil && prev.Next != nil {
        lastN := prev.Next
        prev.Next = lastN.Next
        lastN.Next = nil
    }
    return dummy.Next
}
```