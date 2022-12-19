
迭代算法

```
func reverseList(head *ListNode) *ListNode {
    r := &ListNode {
        Val: -1,
        Next: nil,
    }
    
    c := head
    n := head
    for c != nil {
        n = c.Next
        c.Next = r.Next
        r.Next = c
        c = n
    }
    
    return r.Next
}
```

递归算法

```
func reverseList(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    h, _ := reverseListRecur(head)
    return h
}

func reverseListRecur(head *ListNode) (h, t *ListNode) {
    
    if head.Next != nil {
        h, t = reverseListRecur(head.Next)
        head.Next = nil
        t.Next = head
        t = head
        return 
    } else {
        h = head
        t = head
        return 
    }
}
```