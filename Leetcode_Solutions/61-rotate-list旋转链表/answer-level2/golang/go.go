### 解题思路
- 记得断链
- 考虑清楚旋转多少次
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    if head == nil || head.Next == nil{
        return head
    }
    //计算链表长度
    cnt := 1
    c := head 
    for c.Next != nil {
        c = c.Next
        cnt++
    }
    //旋转操作
    for i := 0; i < k%cnt; i++ {
        next := head.Next
        cur := head
        for next.Next != nil {
            next = next.Next
            cur = cur.Next
        }
        cur.Next = nil
        next.Next = head
        head = next
    }
    return head
}
```