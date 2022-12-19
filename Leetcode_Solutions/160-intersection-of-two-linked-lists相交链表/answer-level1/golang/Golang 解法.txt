
- 先计算各自单链表长度
- 然后从两个链表相同对应位置开始遍历

```
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    la := 0
    lb := 0
    ca := headA
    cb := headB
    
    for ca != nil {
        ca = ca.Next
        la++
    }
    
    for cb != nil {
        cb = cb.Next
        lb++
    }
    
    ca = headA
    cb = headB
    
    if la > lb {
        diff := la - lb
        for diff > 0 {
            ca = ca.Next
            diff--
        }
    } else if la < lb {
        diff := lb - la
        for diff > 0 {
            cb = cb.Next
            diff--
        }
    }
    
    for ca != nil && cb != nil {
        if ca != cb {
            ca = ca.Next
            cb = cb.Next
        } else {
            break
        }
    }
    
    return ca
}
```
