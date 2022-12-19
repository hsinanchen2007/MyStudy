1. 方法1， 通过hash遍历查找环的入口
func detectCycle(head *ListNode) *ListNode {
    if head == nil || head.Next == nil{
        return nil
    }
    var hash = make(map[*ListNode]int)
    for head != nil {
        if _,ok := hash[head]; ok{
            return head
        }
        hash[head] = head.Val
        head = head.Next
    }
    
    return nil
}

2. 方法2： 通过快慢指针先判断是否有环，再查找环的入口
func detectCycle(head *ListNode) *ListNode {
    if head == nil || head.Next == nil{
        return nil
    }
    fast, slow := head, head
    for fast != nil && fast.Next != nil{
        fast = fast.Next.Next
        slow = slow.Next
        if fast == slow{
            break
        }
    }
    
    if fast == nil || fast.Next == nil{
        return nil
    }
    
    //has cycle
    for fast != head{
        fast = fast.Next
        head = head.Next
    }
    return fast
}