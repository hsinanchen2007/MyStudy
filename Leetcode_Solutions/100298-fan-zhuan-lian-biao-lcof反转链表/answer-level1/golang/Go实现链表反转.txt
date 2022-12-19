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
    if head == nil{
        return nil
    }
    var pre *ListNode
    cur := head
    for cur != nil{
        next := cur.Next
        cur.Next = pre
        pre = cur
        cur = next
    }
    return pre
}
```