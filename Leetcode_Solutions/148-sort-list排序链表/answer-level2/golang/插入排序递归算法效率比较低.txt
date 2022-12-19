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
func sortList(head *ListNode) *ListNode {
    return insertSort(head)
}

func insertSort(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    // 递归
    head.Next = insertSort(head.Next)
    // 插入
    node := head
    for node.Next != nil && node.Val > node.Next.Val {
        node.Val, node.Next.Val = node.Next.Val, node.Val
        node = node.Next
    }
    return head
}
```