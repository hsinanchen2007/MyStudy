```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    dh :=&ListNode{}
    curr := dh
    p := l1
    q := l2
    pre := 0
    for p != nil || q != nil{
        e1 := 0
        if p != nil {
            e1 = p.Val
            p = p.Next
        }
        e2 := 0
        if q != nil {
            e2 = q.Val
            q = q.Next
        }
        //fmt.Println(e1, e2)
        sum := e1+e2+pre
        pre = sum/10
        curr.Next = &ListNode{Val:sum%10}
        curr = curr.Next
    }
    if pre >0 {
        curr.Next = &ListNode{Val:pre}
    }
    return dh.Next
}
```