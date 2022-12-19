```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reverse(head *ListNode)*ListNode{
    if head == nil{
        return head
    }
    
    var pre *ListNode
    cur := head
    for cur != nil{
        next := cur.Next
        cur.Next = pre
        pre = cur 
        cur = next
    }
    return pre
}

func isPalindrome(head *ListNode) bool {
    if head == nil ||head.Next == nil{
        return true
    }
    head2 := head
    slow ,fast := head,head
    for fast != nil && fast.Next!=nil &&fast.Next.Next != nil{
        fast = fast.Next.Next
        slow = slow.Next
    }
    head1 := slow.Next
    head1 = reverse(head1)
    for head1!= nil{
        if head1.Val != head2.Val{
            return false
        }else{
            head1 = head1.Next
            head2 = head2.Next
        }
    }
    return true
}
```
