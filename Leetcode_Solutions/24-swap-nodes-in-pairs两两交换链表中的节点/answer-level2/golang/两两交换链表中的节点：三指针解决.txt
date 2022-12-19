给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

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

    if head == nil|| head.Next == nil {
        return head
    }
    p1 := head
    p2 := head.Next
    p3 := head.Next.Next
    // 第二个结点是最后结果的头节点，先记录下来
    ret := p2
    for {
        p1.Next = p3
        p2.Next = p1
        if p3 == nil || p3.Next == nil {
            break
        } else {
            p1.Next = p3.Next
            p1 = p3
            p2 = p1.Next
            p3 = p2.Next
        }
    }
    return ret
}
```