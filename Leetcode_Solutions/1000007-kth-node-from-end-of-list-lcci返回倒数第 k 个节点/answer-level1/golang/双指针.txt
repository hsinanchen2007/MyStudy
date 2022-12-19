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
func kthToLast(head *ListNode, k int) int {
    slow := head 
    for head !=nil && k > 0{
        head = head.Next
        k--
    }
    for head != nil {
        head = head.Next
        slow = slow.Next
    }
    return slow.Val
}
```