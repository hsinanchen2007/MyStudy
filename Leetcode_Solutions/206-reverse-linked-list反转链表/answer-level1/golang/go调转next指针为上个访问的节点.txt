### 解题思路
遍历链表，用一个变量last存储上一个访问的节点，将当前节点的next修改为上一个节点，更新last为head，head往后移动

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
    var last *ListNode
    for head != nil {
        head, head.Next, last = head.Next, last, head
    }
    return last
}
```