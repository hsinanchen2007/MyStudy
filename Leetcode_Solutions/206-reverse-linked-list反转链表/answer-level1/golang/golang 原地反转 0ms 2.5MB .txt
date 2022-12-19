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
    if head == nil{
        return nil
    }
    var newNode *ListNode     //新链表 起始为nil
    for head!=nil{
        next := head.Next  // 保存当前节点的下一个节点指针
        head.Next = newNode  //将当前节点变为新链表的头节点
        newNode = head     //更新保存新链表的头结点
        head=next   //将下一个节点保存为新的head
    }
    return newNode
}

```