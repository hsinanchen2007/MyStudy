/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    p1,p2 := l1,l2
    add := 0
    var back *ListNode
    for p1!=nil && p2!=nil {
        if add==0 {
            if p1.Val + p2.Val >= 10 {
                add = 1 
            }
            p1.Val = (p1.Val + p2.Val)%10
        } else {
            
            if p1.Val + p2.Val + add >= 10 {
                p1.Val = (p1.Val + p2.Val+add)%10
                add = 1
            } else {
                p1.Val = (p1.Val + p2.Val+add)%10
                add = 0
            }
            
        }
        if p1 != nil && p1.Next ==nil{
            back = p1
        }
        p1 = p1.Next
        p2 = p2.Next
        
    }
    if p1 ==nil && p2 == nil {
        if add == 1 {
            p1 = new(ListNode)
            p1.Val = 1
            back.Next = p1
        }
        return l1
    }
    
    if p1 !=nil {
        if add > 0 {
            tmp := new(ListNode)
            tmp.Val = 1
            addTwoNumbers(p1,tmp)
        }
        
        return l1
    }
    if p2 != nil {
        p1 = p2
        if add == 1 {
            tmp := new(ListNode)
            tmp.Val = 1
            back.Next = addTwoNumbers(p1,tmp)
        } else {
            back.Next = p1
        }
        
        return l1
    }
    return nil
}