```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func swapPairs(head *ListNode) *ListNode {
    if head == nil{
        return head
    }
    dummnyhead := &ListNode{
        Val :-1,
        Next:head,
    }
    p := dummnyhead
    for p.Next != nil&&p.Next.Next!= nil{
        node1 := p.Next
        node2 := node1.Next
        next := node2.Next
        p.Next = node2
        node2.Next = node1
        node1.Next =next
        p = node1
    }
    return dummnyhead.Next
}
```
