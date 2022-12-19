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
 // 记录后继节点
var successor *ListNode
 // 递归反转
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    if m == 1 {
        return reverseN(head, n)
    }
    head.Next = reverseBetween(head.Next, m-1, n-1)
    return head
}

func reverseN(head *ListNode, n int) *ListNode {
    // 递归退出条件
    if n == 1 {
        // 保存后继节点
        successor = head.Next
        return head
    }
    last := reverseN(head.Next, n - 1)
    head.Next.Next = head
    head.Next = successor
    return last
}
```