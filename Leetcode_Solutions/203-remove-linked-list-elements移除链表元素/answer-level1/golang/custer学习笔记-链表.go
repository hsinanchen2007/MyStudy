# 使用虚拟头节点实现
```go
func removeElements(head *ListNode, val int) *ListNode {
    dummy := new(ListNode) // 新建一个虚拟头节点
    dummy.Next = head      // 虚拟头节点指向head
    notEqual := dummy      // 新建一个游标
    for notEqual.Next != nil {
        if notEqual.Next.Val == val {
            notEqual.Next = notEqual.Next.Next
        } else {
            notEqual = notEqual.Next
        }
    }
    return dummy.Next
}
```

# 不使用虚拟头节点实现
```go
func removeElements(head *ListNode, val int) *ListNode {
    for head != nil && head.Val == val {
        head = head.Next
    }
    if head == nil {
        return nil
    }
    prev := head
    for prev.Next != nil {
        if prev.Next.Val == val {
            prev.Next = prev.Next.Next
        } else {
            prev = prev.Next
        }
    }
    return head
}
```

# 使用递归实现
```go
func removeElements(head *ListNode, val int) *ListNode {
    if head == nil {
        return nil
    }
    head.Next = removeElements5(head.Next, val)
    if head.Val == val {
        return head.Next
    } else {
        return head
    }
}

```