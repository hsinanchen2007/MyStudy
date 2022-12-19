```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil{
        return nil
    }
    dummnyhead := &ListNode{
        Val :-1,
        Next:head,
    }
    cur := dummnyhead
    for cur.Next!= nil&&cur.Next.Next!= nil{
        if cur.Next.Val ==cur.Next.Next.Val{
            tmp := cur.Next.Val
            for cur.Next != nil &&cur.Next.Val == tmp{
                    cur.Next = cur.Next.Next
            }
        }else {
            cur = cur.Next
        }
        
    }
    return dummnyhead.Next
}
```
