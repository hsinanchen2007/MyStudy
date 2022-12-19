### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(head *ListNode, val int) *ListNode {
    if head.Val==val{
        return head.Next
    }
    slow,fast:=head,head.Next
    for{
        if fast.Val==val{
            slow.Next=fast.Next
            break
        }
        fast=fast.Next
        slow=slow.Next
    }
    return head
}
```