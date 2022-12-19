### 解题思路
双指针，遍历的同时改变指针即可。
连续赋值好省事  

### 代码

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    if nil == head {
        return head
    }
    cur, next := head, head.Next
    for ; nil != next; cur, next, next.Next = next, next.Next, cur {
    }
    head.Next = nil
    return cur
}
``` 