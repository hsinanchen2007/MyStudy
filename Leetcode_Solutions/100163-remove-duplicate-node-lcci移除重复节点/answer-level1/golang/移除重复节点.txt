### 解题思路
遍历链表，发现重复元素，则从链表中移除。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeDuplicateNodes(head *ListNode) *ListNode {
    md := make(map[int]int8)
    p := head
    var prev *ListNode
    for p != nil {
        if md[p.Val] > 0 {
            prev.Next = p.Next
        } else {
            md[p.Val]++
            prev = p
            
        }
        p = p.Next
    }
    return head
}
```