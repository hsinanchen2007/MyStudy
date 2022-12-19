
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    if head==nil || head.Next == nil{
        return true
    }
    fast,slow := head,head
    for fast != nil && fast.Next != nil{
        fast = fast.Next.Next
        slow = slow.Next
    }
    right := reverse(slow)
    left := head
    for right != nil{
        if right.Val == left.Val{
            right =right.Next
            left = left.Next
        }else{
            return false
        }
    }
    return true
}

func reverse(head *ListNode)*ListNode{
    if head == nil{
        return nil
    }
    var pre *ListNode
    cur:= head
    for cur != nil{
        next := cur.Next
        cur.Next = pre
        pre = cur 
        cur = next
    }
    return pre
}
```