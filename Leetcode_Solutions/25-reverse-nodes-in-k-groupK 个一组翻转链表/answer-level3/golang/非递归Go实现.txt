```
func reverseKGroup(head *ListNode, k int) *ListNode {
    dummy := &ListNode{0, head}
    pre, end := dummy, dummy
    for end.Next != nil {
        for i := 0; i < k && end != nil; i++ {
            end = end.Next
        }

        if end == nil {
            break
        }

        start := pre.Next
        next := end.Next
        end.Next = nil

        pre.Next = reverse(start)
        start.Next = next
        pre = start
        end = pre
    }

    return dummy.Next
}

func reverse(head *ListNode) *ListNode {
    var pre *ListNode
    pre = nil
    cur := head
    for cur != nil {
        //tmp := cur.Next
        //cur.Next = pre
        //pre = cur
        //cur = tmp
        cur.Next, pre, cur = pre, cur, cur.Next
    }
    return pre
}
```
