### 解题思路
此处撰写解题思路
pre用来保存原来单链表中cur的前置顺序 
next 用于记住原来单链表中cur的后置指针

特变要注意的是最后需要将原来的head.Next 设置为nil

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

    pre := new(ListNode)
    cur := head

    for cur != nil {
        next := cur.Next
        cur.Next = pre

        pre = cur
        cur = next
    }

    head.Next = nil
    
    return pre
}
```