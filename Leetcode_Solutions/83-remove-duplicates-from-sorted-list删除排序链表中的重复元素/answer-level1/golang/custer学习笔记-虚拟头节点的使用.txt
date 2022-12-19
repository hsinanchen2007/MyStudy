# 使用虚拟头节点
```go
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    dummy := &ListNode{Next: head}
    pre := dummy
    for cur := head; cur.Next != nil; cur = cur.Next {
        if cur.Val == cur.Next.Val {
            pre.Next = cur.Next
        } else {
            pre = cur
        }
    }
    return dummy.Next
}
```

# 不使用虚拟头节点
```go
// Time Complexity: O(n), Space Complexity: O(1)
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil { // 链表为空返回指针
        return head
    }
    // 快慢两个指针分别初始指向第一和第二个节点
    cur, next := head, head.Next
    for next != nil { // 只要快指针不为空，执行以下操作
        // 如果快慢指针指向的值相同
        if cur.Val == next.Val {
            // 把慢指针指向快指针的下一个节点，跳过重复的节点
            cur.Next = next.Next
        } else { // 如果两个节点指向的值不同
            // 慢指针向后移动一位
            cur = cur.Next
        }
        // 无论快慢指针的节点是否相同，快指针都需要往后移动一位
        next = next.Next
    }
    return head // 返回节点去重的单链表
}
```