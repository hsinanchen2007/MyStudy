```
func reorderList(head *ListNode)  {
    if head == nil || head.Next == nil{
        return 
    }
    fast ,slow := head,head
    for fast != nil &&fast.Next!= nil {
        fast = fast.Next.Next
        slow = slow.Next
    }
    left := head
    right := slow.Next
    slow.Next = nil
    right = Reverse(right)

    for right != nil{
        lNext := left.Next
        rNext := right.Next
        left.Next = right
        right.Next = lNext
        left = lNext
        right = rNext
    }
    
}

func Reverse(head *ListNode)*ListNode{
    if head == nil{
        return nil
    }
    var pre *ListNode
    cur := head
    for cur != nil{
        next := cur.Next
        cur.Next = pre
        pre = cur
        cur = next
    }
    return pre
}
```
