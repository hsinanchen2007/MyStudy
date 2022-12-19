```
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var dummy *ListNode = &ListNode{}
    pre := dummy
    var carry int = 0
    for l1 != nil || l2 != nil ||  carry != 0 {
        sum := 0
        if l1 != nil {
            sum += l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            sum += l2.Val
            l2 = l2.Next
        }
        sum += carry
        cur := &ListNode{Val:sum % 10}
        pre.Next = cur
        pre = cur
        carry = sum / 10
    }
    return dummy.Next
}
```
