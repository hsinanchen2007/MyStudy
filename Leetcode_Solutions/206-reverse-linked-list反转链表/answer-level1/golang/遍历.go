### 解题思路
此处撰写解题思路
注意输入为空链表的情况

### 代码

```golang
func reverseList(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    var nlist *ListNode
    node, next := head, head.Next
    for node != nil {
        node.Next = nlist
        nlist = node
        node = next
        if next != nil {
            next = next.Next
        }
    }
    return nlist
}
```