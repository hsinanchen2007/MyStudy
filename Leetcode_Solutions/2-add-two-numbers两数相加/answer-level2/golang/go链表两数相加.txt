```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var l *ListNode = &ListNode{}
    pre := l
    flag := 0
    for l1 != nil || l2 != nil {
        pre.Next = &ListNode{}
        p := pre.Next
        x := 0
        y := 0
        if l1 != nil {
            x = l1.Val
        }
        if l2 != nil {
            y = l2.Val
        }
        p.Val = (x + y + flag) % 10
        flag = (x + y + flag) / 10
        pre = p
        if l1 != nil {
            l1 = l1.Next
        }
        if l2 != nil {
            l2 = l2.Next
        }
    }
    if flag != 0 {
        pre.Next = &ListNode{Val: flag}
    }
    return l.Next
}
```
