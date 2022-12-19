### 解题思路
太简单，看代码吧

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
    len := 0
    p := head
    for p != nil {
        len++
        p = p.Next
    }
    n := 0
    p = head
    for p != nil {
        if n == len - k {
            return p
        }
        n++
        p = p.Next
    }

    return nil    
}
```