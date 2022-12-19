```
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1 == nil && l2 != nil {
        return l2
    }
    if l1 != nil && l2 == nil {
        return l1
    }
    head := l1
    prel1 := l1
    for l2 != nil && l1 != nil {
        if l2.Val < l1.Val {
            t := l2.Next
            if l1 == head {
                p := l2
                p.Next = l1
                head = p
                prel1 = head
            } else {
                p := l2
                p.Next = prel1.Next
                prel1.Next = p
                prel1 = prel1.Next
            }
            l2 = t
        } else {
            if l1 != head {
                prel1 = prel1.Next
            }
            l1 = l1.Next
        }
    }
    
    if prel1 != nil && l2 != nil {
        prel1.Next = l2
    }
    return head
}
```
