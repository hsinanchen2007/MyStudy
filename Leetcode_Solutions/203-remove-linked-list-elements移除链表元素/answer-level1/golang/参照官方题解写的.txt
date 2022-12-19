```
func removeElements(head *ListNode, val int) *ListNode {
    tmp := new(ListNode)
    tmp.Next = head
    pre, curr := tmp, head
    for curr != nil {
        if curr.Val == val {
            pre.Next = curr.Next
        }else{
            pre = curr
        }
        curr = curr.Next
    }
    return tmp.Next
}
```
