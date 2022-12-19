```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func oddEvenList(head *ListNode) *ListNode {
    if head == nil{
        return head
    }
    dummnyhead1 := &ListNode{
        Val :-1,
        Next:nil,
    }
    dummnyhead2 := &ListNode{
        Val :-1,
        Next:nil,
    }
    cur1,cur2 := dummnyhead1,dummnyhead2
    cur := head
    for i:=0;cur!= nil;i++{
        if i%2 ==0{
            next := cur.Next
            cur1.Next = cur
            cur1 = cur1.Next
            cur1.Next = nil
            cur = next
        }else{
            next := cur.Next
            cur2.Next = cur
            cur2 = cur2.Next
            cur2.Next = nil
            cur = next
        }
    }
    if dummnyhead2.Next == nil{
        return dummnyhead1.Next
    }else{
        cur1.Next = dummnyhead2.Next
        return dummnyhead1.Next
    }
}
```

