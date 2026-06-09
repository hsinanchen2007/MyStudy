进阶思路分三步走：
1. 首先利用快慢指针寻找中间节点；
2. 然后反转中间节点，得到（原链表的）尾节点；
3. 最后逐一比较前后两半的节点值；

```
func isPalindrome(head *ListNode) bool {  
    tail := reverse(middle(head))
   
    for head != nil && tail != nil {
        if head.Val != tail.Val {
            return false
        }
        head = head.Next
        tail = tail.Next
    }
    
    
    return true
}
// 寻找中间节点
func middle(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    
    fast, slow := head, head
    for fast != nil && fast.Next != nil {
        fast = fast.Next.Next
        slow = slow.Next
    }
    return slow
}
// 反转链表
func reverse(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    
    cur := head.Next
    head.Next = nil
    for cur != nil {
        next := cur.Next
        cur.Next = head
        head = cur
        cur = next
    }
    return head
}
```
