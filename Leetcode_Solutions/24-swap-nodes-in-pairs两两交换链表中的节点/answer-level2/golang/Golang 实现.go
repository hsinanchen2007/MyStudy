
借助头指针简化实现

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    d := &ListNode {
        Val: -1,
        Next: nil,
    }
    
    d.Next = head
    pre := d
    n1 := head
    n2 := n1.Next
    
    for n1 != nil && n2 != nil {
        n3 := n2.Next
        pre.Next = n2
        n1.Next = n3
        n2.Next = n1
        
        pre = n1
        n1 = pre.Next
        if n1 != nil {
            n2 = n1.Next
        } else {
            n2 = nil
        }
        
    }
    
    return d.Next
}
```