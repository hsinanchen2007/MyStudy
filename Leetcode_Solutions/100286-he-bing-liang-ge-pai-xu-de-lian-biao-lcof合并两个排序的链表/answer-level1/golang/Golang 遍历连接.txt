### 解题思路
8ms 4.1MB
定义一个头指针和连接指针, 使用连接指针遍历连接两个链表, 并将剩余部分连接

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
    var head *ListNode

    if l1 == nil {
        return l2
    } else if l2 == nil {
        return l1
    }

    if l1.Val < l2.Val {
        head = l1
        l1 = l1.Next
    } else {
        head = l2
        l2 = l2.Next
    }
    pre := head

    // 连接
    for l1 != nil && l2 != nil {
        if l1.Val < l2.Val {
            pre.Next = l1
            l1 = l1.Next
        } else {
            pre.Next = l2
            l2 = l2.Next
        }
        pre = pre.Next
    }

    // 连接剩余部分
    if l1 != nil {
        pre.Next = l1
    } else if l2 != nil {
        pre.Next = l2
    }

    return head
}
```