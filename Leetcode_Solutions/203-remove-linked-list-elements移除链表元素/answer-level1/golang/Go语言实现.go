```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
    if head == nil{
        return head
    }
    dummnyhead := &ListNode{
        Val:-1,
        Next:head,
    }
    cur := dummnyhead
    for cur.Next!= nil {
        if cur.Next.Val == val{
            cur.Next = cur.Next.Next
        }else{
            cur = cur.Next
        }
    }
    return dummnyhead.Next
}
```
