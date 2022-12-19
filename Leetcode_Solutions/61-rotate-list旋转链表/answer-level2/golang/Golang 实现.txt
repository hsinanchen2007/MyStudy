
- 先确认新的链表头然后进行本地修改
- 借助哨兵结点简化操作


```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    dummy := &ListNode {
        Val: -1,
        Next: nil,
    }
    
    dummy.Next = head
    tmp := head
    var curtail *ListNode = nil
    length := 0
    for tmp != nil {
        length++
        curtail = tmp
        tmp = tmp.Next
    }
    
    k = k % length
    if k == 0 {
        return dummy.Next
    }
    
    preNewHead := dummy
    newHead := dummy.Next
    tmp = head
    for k != 0 {
        tmp = tmp.Next
        k--
    }
    
    for tmp != nil {
        tmp = tmp.Next
        preNewHead = newHead
        newHead = newHead.Next
    }
    
    dummy.Next = newHead
    curtail.Next = head
    preNewHead.Next = nil
    
    return dummy.Next
    
}
```