### 解题思路

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
        return nil
    }
    if head.Next == nil {
        return head
    }
    var cur, next *ListNode
    //cur 指向链表中第二个结点
    cur = head.Next
    //将head的指针域置为空，作为最后一个结点
    head.Next = nil
    for cur != nil {
        //next为 cur的后继结点
        next = cur.Next
        //将cur结点指针域指向head
        cur.Next = head
        //head向前挪动
        head = cur
        // cur重新指向原链表
        cur = next
    }
    return head
}

```
