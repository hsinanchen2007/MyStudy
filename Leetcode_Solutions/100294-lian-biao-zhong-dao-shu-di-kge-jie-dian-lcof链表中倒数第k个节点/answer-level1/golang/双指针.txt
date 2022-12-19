### 解题思路
双指针，让前一个先走`k-1`步，然后开始同时走，当第一个在尾结点的时候倒数第二个将恰好在倒数第k个节点处

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
    first := head
    second := head
    for i := 0; i < k-1; i++{
        first = first.Next
    }
    for first.Next != nil {
        first = first.Next
        second = second.Next
    }
    return second
    
}
```