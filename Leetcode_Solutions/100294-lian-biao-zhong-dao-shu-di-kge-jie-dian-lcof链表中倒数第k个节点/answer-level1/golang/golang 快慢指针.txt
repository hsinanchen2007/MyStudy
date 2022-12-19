### 解题思路
单链表解题思路：
* 哨兵节点
* 快慢指针

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
    
    slow, fast := head, head
    for i := 0; i < k; i++ {
        fast = fast.Next
    }
    if fast == nil {
        return head
    }
    for fast != nil {
        fast = fast.Next
        slow = slow.Next
    }
    return slow
}
```