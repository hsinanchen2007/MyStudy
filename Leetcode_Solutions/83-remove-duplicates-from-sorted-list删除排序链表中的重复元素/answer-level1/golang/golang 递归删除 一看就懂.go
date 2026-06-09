```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    head.Next = deleteDuplicates(head.Next)
    if head.Val == head.Next.Val{
        head.Next = head.Next.Next
    }
    return head 
}
```
