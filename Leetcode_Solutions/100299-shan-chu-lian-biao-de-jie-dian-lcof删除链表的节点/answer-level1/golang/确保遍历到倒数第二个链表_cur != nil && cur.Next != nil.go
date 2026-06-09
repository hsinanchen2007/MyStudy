
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(head *ListNode, val int) *ListNode {
    if head == nil {
        return nil
    }
    dummy := &ListNode{Next:head}
    //确保遍历到倒数第二个链表:cur != nil && cur.Next != nil
    for cur := dummy; cur != nil && cur.Next != nil;cur = cur.Next  {
        if cur.Next.Val == val {
            cur.Next = cur.Next.Next
        }
    }
    return dummy.Next
}
```