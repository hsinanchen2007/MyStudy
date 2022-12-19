这是一个典型的K路归并问题，一般两种解法：
1. 分治，递归分解成多个二路归并
2. 最小堆

鉴于笔者使用的是Go，因此笔者使用了第一种方法，不用造轮子
```go
func mergeKLists(lists []*ListNode) *ListNode {
    listsLen := len(lists)
    if listsLen == 0 {
        return nil
    } else if listsLen == 1 {
        return lists[0]
    }

    mid := listsLen / 2
    left := mergeKLists(lists[:mid])
    right := mergeKLists(lists[mid:])

    return mergeTwoLists(left, right)
}

func mergeTwoLists(l1, l2 *ListNode) *ListNode {
    if l1 == nil || l2 == nil {
        if l1 != nil {
            return l1
        } else if l2 != nil {
            return l2
        } else {
            return nil
        }
    }

    var head, tail *ListNode
    if l1.Val < l2.Val {
        head, tail = l1, l1
        l1 = l1.Next
    } else {
        head, tail = l2, l2
        l2 = l2.Next
    }
    for l1 != nil && l2 != nil {
        if l1.Val < l2.Val {
            tail.Next = l1
            tail = l1
            l1 = l1.Next
        } else {
            tail.Next = l2
            tail = l2
            l2 = l2.Next
        }
    }
    for l1 != nil {
        tail.Next = l1
        tail = l1
        l1 = l1.Next
    }
    for l2 != nil {
        tail.Next = l2
        tail = l2
        l2 = l2.Next
    }

    return head
}
```