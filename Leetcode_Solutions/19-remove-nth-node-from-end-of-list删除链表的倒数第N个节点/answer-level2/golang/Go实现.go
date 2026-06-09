```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    if head == nil{
        return head
    }
    dummnyhead := &ListNode{
        Val:-1,
        Next:head,
    }
    cur := dummnyhead
    fast,slow := cur,cur
    for i:= 0;i<n;i++{
        fast = fast.Next
    }
    if fast.Next == nil{
        slow.Next = slow.Next.Next
        return dummnyhead.Next
    }else{
        for fast!= nil&&fast.Next!= nil{
            fast = fast.Next
            slow = slow.Next
        }
        slow.Next = slow.Next.Next
        return dummnyhead.Next
    }
}
```
