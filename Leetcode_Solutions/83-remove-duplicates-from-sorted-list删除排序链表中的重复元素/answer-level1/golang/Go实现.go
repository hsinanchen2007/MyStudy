```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil ||head.Next == nil{
        return head
    }
    dummnyhead := &ListNode{
        Val :-1,
        Next: head,
    }
    cur := dummnyhead
    for cur.Next != nil&&cur.Next.Next!= nil{
        if cur.Next.Val == cur.Next.Next.Val{
            cur.Next = cur.Next.Next
        }else{
            cur = cur.Next
        }
    }
    return dummnyhead.Next
    
}


```
