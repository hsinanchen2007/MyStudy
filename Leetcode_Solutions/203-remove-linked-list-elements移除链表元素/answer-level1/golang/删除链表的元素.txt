### 解题思路
给当前链表加一个头节点，这样子便于修改前后指针的引用。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
    listNode := &ListNode{
        Next: head,
    }

    i := listNode
    for i.Next != nil {
        if i.Next.Val != val {
            i = i.Next
            continue
        }
        i.Next = i.Next.Next
    }

    return listNode.Next
}
```