### 官方迭代golang
官方迭代golang
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    head := &ListNode{}
    pre := head
    for l1 != nil && l2 != nil {
        if l1.Val > l2.Val {
            pre.Next = l2
            l2 = l2.Next
        }else {
            pre.Next = l1
            l1 = l1.Next

        }
        pre = pre.Next
    }
    if l1 == nil {
        pre.Next = l2
    }else {
        pre.Next = l1
    }
    return head.Next
    
}
```