### 解题思路

参考官方迭代法，实现的golang版本

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
    var prev *ListNode
    curr := head
    for curr != nil {
        curr.Next,prev,curr = prev,curr,curr.Next
    }
    return prev
}
```