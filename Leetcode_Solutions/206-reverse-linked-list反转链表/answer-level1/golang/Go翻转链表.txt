这道题比较简单,就是遍历链表,使用两个指针记录当前节点和前一个节点,然后把当前节点移动到链表头,为了方便理解,这里用了一个空表头,只要遍历过一个节点,把节点加入空表头下即可

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
    vhead := &ListNode{
        Next: head,
    }
    cur := head.Next
    prev := head
    for cur != nil {
        prev.Next = cur.Next
        cur.Next = vhead.Next
        vhead.Next = cur
        cur = prev.Next
    }
    return vhead.Next
}
```