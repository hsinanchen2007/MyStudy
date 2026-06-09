### 解题思路
先判断是否满足条件。然后使用三指针和递归的方式反转

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
    if head == nil {
        return nil
    }
    var (
        cur = head
        prev,next *ListNode
        count = k
    )
    temp := count
    tcur := head
    for tcur != nil && temp > 0 {
        tcur = tcur.Next
        temp--
    }
    if temp > 0 {
        return head
    }

    for cur != nil && count > 0 {
        next = cur.Next
        cur.Next = prev
        prev = cur
        cur = next
        count--
    }
    if cur != nil {
        top := reverseKGroup(cur,k)
        head.Next = top
    }
    return prev
}
```