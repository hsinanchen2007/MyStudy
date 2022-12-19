

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    if head == nil{
        return nil
    }
    dummnyhead1,dummnyhead2 := &ListNode{-1,nil},&ListNode{-1,nil}
    cur1,cur2 := dummnyhead1,dummnyhead2
    cur := head
    for cur != nil{
        if cur.Val <x{
            cur1.Next = cur
            cur = cur.Next
            cur1 = cur1.Next
            cur1.Next = nil
        }else if cur.Val >=x{
            cur2.Next = cur
            cur = cur.Next
            cur2 = cur2.Next
            cur2.Next = nil
        }
    }
    cur1.Next = dummnyhead2.Next
    return dummnyhead1.Next
}
```