

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    i := head
    j := i.Next
    for j != nil {
        if i.Val != j.Val {
            if i.Next != j {
                i.Next = j
            }
            i = j
        }
        j = j.Next
    }
    i.Next = nil
    return head
}
```