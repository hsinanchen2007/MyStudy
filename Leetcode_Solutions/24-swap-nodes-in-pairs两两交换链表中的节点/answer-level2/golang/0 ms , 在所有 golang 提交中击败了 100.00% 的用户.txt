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
func swapPairs(head *ListNode) *ListNode {
    if nil == head || nil == head.Next {
        return head
    }
    pre := &ListNode{
        Val: 0,
        Next: nil,
    }
    cur := pre
    cur.Next = head
    for nil != cur.Next && nil != cur.Next.Next {
        odd := cur.Next
        even := cur.Next.Next

        // 偶数位指向奇数位
        cur.Next = even
        // 奇数位指向当前节点的下一节点
        odd.Next = cur.Next.Next
        // 当前节点下一位指向偶数位
        cur.Next = even
        // 更新cur
        cur = odd

        cur.Next = even
        odd.Next = even.Next
        even.Next = odd
        cur = odd
    }
    return pre.Next
}
```