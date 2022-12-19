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
        return head
    }
    cur := head
    var pre *ListNode
    tmp := &ListNode{}
    for true{
        if cur.Next == nil{
            cur.Next = pre
            break
        }
        tmp = cur.Next
        cur.Next = pre
        pre = cur
        cur = tmp
    }
    return cur
}
```