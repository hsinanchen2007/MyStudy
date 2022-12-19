该题解借鉴了"哑节点+快慢指针"的思想，算法如下：

```go
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    dummy := &ListNode{Val: -1}
    dummy.Next = head
    slow := dummy
    fast := head
    for fast.Next != nil {
        if fast.Val != fast.Next.Val {
            if slow.Next == fast {
                // 说明slow和fast之间没有重复元素，更新slow节点
                slow = fast
            } else {
                // 说明slow和fast之间有重复元素，更新slow的next节点
                slow.Next = fast.Next
            }
        }
        fast = fast.Next
    }
    // 再次检查slow和fast
    if slow.Next != nil && slow.Next != fast && slow.Next.Val == fast.Val {
        slow.Next = nil
    }
    return dummy.Next
}
```