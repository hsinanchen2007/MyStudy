func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var a int
    switch {
         case l1 == nil && l2 != nil :
        a =l2.Val
    
    case l1 != nil && l2 == nil :
        a = l1.Val
    
    case l1 == nil && l2 == nil :
        return nil
    

    default :
   
    a = l1.Val+l2.Val
    }
    if a >= 10 {
        a = a%10
        if l1!=nil&&l1.Next != nil {
            l1.Next.Val++
        }else if l2 != nil&&l2.Next != nil {
            l2.Next.Val++
        }else {
            return &ListNode{a,&ListNode{1,nil}}
        }
    }
    if l1 == nil {
        return &ListNode{a,addTwoNumbers(nil,l2.Next)}
    }
    if l2 ==  nil {
        return &ListNode{a,addTwoNumbers(l1.Next,nil)}
    }
    return &ListNode{a,addTwoNumbers(l1.Next,l2.Next)}
}