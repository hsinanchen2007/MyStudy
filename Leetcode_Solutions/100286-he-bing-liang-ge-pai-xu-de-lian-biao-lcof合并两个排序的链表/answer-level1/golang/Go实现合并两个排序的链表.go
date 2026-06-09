

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1 == nil &&l2 == nil {
        return nil
    }
    if l1 == nil && l2 != nil{
        return l2
    }
    if l1 != nil && l2 == nil{
        return l1
    }
    dummnyhead := &ListNode{Val:-1,Next:nil}
    cur := dummnyhead
    if l1.Val<=l2.Val{
        cur.Next =l1
        cur = cur.Next
        cur.Next = mergeTwoLists(l1.Next,l2)
    }else{
        cur.Next =l2
        cur = cur.Next
        cur.Next = mergeTwoLists(l1,l2.Next)
    }
    return dummnyhead.Next
}
```