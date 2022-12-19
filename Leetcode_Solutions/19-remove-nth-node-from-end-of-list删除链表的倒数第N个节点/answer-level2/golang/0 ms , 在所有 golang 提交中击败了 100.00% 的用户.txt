### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    if nil == head || nil == head.Next {
        return nil
    }
    // 设置一个哑节点
    pre := &ListNode{
        Val: 0,
        Next: head,
    }
    first, second := pre, pre
    for i := 1; i<n+2; i++ {
        first = first.Next
    }

    for nil != first {
        first = first.Next
        second = second.Next
    }
    second.Next = second.Next.Next
    return pre.Next
}
```