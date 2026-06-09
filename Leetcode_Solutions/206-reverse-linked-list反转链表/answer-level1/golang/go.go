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
    if head == nil {
        return nil
    }
    var p1, p2 *ListNode
    for head != nil {
        
        p2 = head.Next 
        head.Next = p1 
        p1 = head 
        head = p2
    }
    return p1
}

```