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
    if head == nil {
        return head
    }
    ret := head
    pre := head
    head = head.Next
    for head != nil {
        next := head.Next
        pre.Next = head.Next
        head.Next = ret
        ret = head
        head = next
    }
    return ret
}
```