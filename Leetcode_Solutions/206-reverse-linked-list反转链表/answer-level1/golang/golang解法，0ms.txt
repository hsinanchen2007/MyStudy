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
func reverseList(head *ListNode) *ListNode {
// 创建前置空节点
    prev := new(ListNode)
    prev = nil

    for head!=nil {
// next指针保存后一个节点
        next := head.Next
// 将链表的next指针指向前置节点
        head.Next=prev
// 进入下一个循环，将前置节点更新为当前节点，将当前节点更新为后一个节点
        prev=head
        head=next
    }
// 返回前置节点
    return prev
}
```