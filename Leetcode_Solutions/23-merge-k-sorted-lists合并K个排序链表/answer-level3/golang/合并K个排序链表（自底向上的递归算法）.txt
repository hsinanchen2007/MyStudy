合并K个排序链表的问题可以拆解成这样的子问题：1）合并第K-1和第K-2两个链表，得到新的排序链表；将新链表作为K-1在与上一条链表进行合并，代码如下：

```go
func mergeKLists(lists []*ListNode) *ListNode {
    if len(lists) == 0 { return nil }
    if len(lists) == 1 { return lists[0] }
    p1 := lists[0]
    p2 := mergeKLists(lists[:1])
    dummy := &ListNode{Val: -1}
    pre := dummy
    for p1 != nil && p2 != nil {
        if p1.Val < p2.Val {
        pre.Next = p1
        p1 = p1.Next
        } else {
        pre.Next = p2
        p2 = p2.Next
        }
        pre = pre.Next
    }
    if p1 != nil { pre.Next = p1 }
    if p2 != nil { pre.Next = p2 }
    return dummy.Next
}
```
