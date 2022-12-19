### 解题思路
0ms 2.2MB
使用双指针, 第一个指针先走, 并开始计数, 计数从1开始, 计数到k后, 第二个指针走

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
    pre := head
    n := 1
    for head.Next != nil {
        if n < k {
            n++
        } else {
            pre = pre.Next
        }
        head = head.Next
    }
    return pre
}
```