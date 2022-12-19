### 解题思路
先将头节点从链表中截断，再用头插法

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
    if (head == nil) {
        return nil
    }
    var p *ListNode
    q := head.Next
    head.Next = nil
    for q != nil {
        p = q.Next
        q.Next = head
        head = q
        q = p
    }
    return head
}
```