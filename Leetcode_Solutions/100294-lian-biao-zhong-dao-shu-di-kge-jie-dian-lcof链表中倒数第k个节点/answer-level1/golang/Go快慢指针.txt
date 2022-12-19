### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
    slow,fast:=head,head
    for i:=0;i<k;i++{
        fast=fast.Next
    }
    for fast!=nil{
        fast=fast.Next
        slow=slow.Next
    }
    return slow
}
```