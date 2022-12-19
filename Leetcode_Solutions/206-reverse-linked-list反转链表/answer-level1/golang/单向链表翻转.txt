### 解题思路
利用递归思想，实现链表翻转
1 保存每次递归前 当前节点和当前节点的next节点，当 当前节点的next为空时，递归中返回当前节点（作为翻转链表的head地址）
2 递归是堆栈实现方式
3 之前每次递归保存的变量（当前节点和当前节点的next节点）出堆栈时，重新把当前节点的next节点 的next指针指向 当前节点
4 返回正向链表的末节点作为翻转链表的head

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
    if head == nil {
        return head
    }
    if head.Next == nil {
        return head
    }
    node := head 
    father := head.Next
    node.Next = nil
    root := reverseList(father)
    father.Next = node
    return root
}
```