```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    if headA ==nil ||headB == nil{
        return nil
    }
    if headA == nil&&headB== nil{
        return nil
    }
    cur1,cur2 := headA,headB
    count1,count2 := Count(headA),Count(headB)
    if count1>count2{
        count3 := count1-count2
        for i := 0;i<count3;i++{
            cur1 = cur1.Next
        }
        for cur1!= nil{
            if cur1==cur2 {
            return cur1
        }else{
            cur1 = cur1.Next
            cur2 = cur2.Next
        }
        }
        return nil
    }else if count1<count2{
        count3 := count2-count1
        for i := 0;i<count3;i++{
            cur2 = cur2.Next
        }
        for cur2!= nil{
            if cur2==cur1 {
            return cur2
        }else{
            cur1 = cur1.Next
            cur2 = cur2.Next
        }
        }
        return nil
    }else{
        for cur2!= nil{
            if cur2==cur1 {
            return cur2
        }else{
            cur1 = cur1.Next
            cur2 = cur2.Next
        }
        }
        return nil
    }
    return nil
}

func Count(head *ListNode)int{
    if head == nil{
        return 0
    }
    count := 0
    for head != nil{
        count ++
        head = head.Next
    }
    return count
}
```
