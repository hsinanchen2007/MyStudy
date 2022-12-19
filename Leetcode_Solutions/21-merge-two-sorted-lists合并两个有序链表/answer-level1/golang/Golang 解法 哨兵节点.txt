

```
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    
    r := &ListNode{
        Val: -1,
        Next: nil,
    }
    t := r
    c1 := l1
    c2 := l2
    n1 := c1
    n2 := c2
    
    for c1 != nil && c2 != nil {
        if c1.Val < c2.Val {
            n1 = c1.Next
            t.Next = c1
            c1.Next = nil
            t = c1
        } else {
            n2 = c2.Next
            t.Next = c2
            c2.Next = nil
            t = c2
        }
        c1 = n1
        c2 = n2
    }
    if c1 != nil {
        t.Next = c1
    }
    if c2 != nil {
        t.Next = c2
    }
    
    return r.Next
    
}
```

时间复杂度：O(n)
空间复杂度：O(1)