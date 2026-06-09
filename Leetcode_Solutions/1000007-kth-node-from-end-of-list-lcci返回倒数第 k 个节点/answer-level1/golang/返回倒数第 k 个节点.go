### 解题思路
先求链表长度，求倒数第几个值即可转化为求第几个节点的值。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func kthToLast(head *ListNode, k int) int {
    len := 0
    p := head
    for p != nil {
        len++
        p = p.Next
    }

    p = head
    index := len - k + 1
    n := 1
    for p != nil {
        if n == index {
            return p.Val
        }
        n++
        p = p.Next
    }
    return -1
}
```