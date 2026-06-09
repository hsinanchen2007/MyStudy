### 解题思路
先通过初始哨兵节点指向整个连标。通过子哨兵节点，以及索引index计数初始为1，每次反转每组的k个节点（小于k个节点的组也正常反转）。反转完k个节点之后，将哨兵节点移动到上次反转后的尾节点，索引index设置为1，再次进行新的反转。全部完成后判断，如果最后一个子哨兵节点的下一个节点不为空，则当读将后面的剩余部分子链表反转。最终返回结果。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
    if head == nil || head.Next == nil || k <= 0 {
        return head
    }
    prev := new(ListNode)
    prev.Next = head
    index := 1
    a_start := prev
    a_head := a_start.Next
    cur := a_head.Next
    for cur != nil {
        a_head.Next = cur.Next
        cur.Next = a_start.Next
        a_start.Next = cur
        cur = a_head.Next
        index++
        if index == k {
            a_start = a_head
            a_head = a_start.Next
            if a_head == nil {
                break
            }
            cur = a_head.Next
            index = 1
        }
    }
    
    a_head = a_start.Next
    if a_head != nil {
        cur = a_head.Next
        for cur != nil {
            a_head.Next = cur.Next
            cur.Next = a_start.Next
            a_start.Next = cur
            cur = a_head.Next
        }
    }
    
    return prev.Next
}
```