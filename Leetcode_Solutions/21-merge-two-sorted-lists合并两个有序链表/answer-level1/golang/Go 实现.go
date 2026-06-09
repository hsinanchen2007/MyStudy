```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1 == nil &&l2 == nil{
        return nil
    }
    if l1 == nil&&l2 != nil{
        return l2
    }
    if l1!= nil &&l2 == nil{
        return l1
    }
    dummnyhead := &ListNode{
        Val:-1,
        Next :nil,
    }
    newhead := dummnyhead
    if l1.Val <l2.Val{
        newhead.Next = l1
        newhead = newhead.Next
        newhead.Next = mergeTwoLists(l1.Next,l2)
    }else{
        newhead.Next = l2
        newhead = newhead.Next
        newhead.Next = mergeTwoLists(l1,l2.Next)
    }
    return dummnyhead.Next
}
```
