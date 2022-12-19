
递归思路：
 1. 前k个节点翻转， 得到一个k个节点的链表
 2. 结束条件：不足k个节点， 直接原样返回
 3. 剩余的链表尾作为参数调用自己
 4. 第3步的返回值连接到第一步得到的链表尾部
```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
    tail := head
    for i:= 0;i < k-1; i++ {
        if tail == nil {
            return head
        }
         tail = tail.Next
    }
    if tail == nil {
        return head
    }
    var pre, cur, next *ListNode
    pre = reverseKGroup(tail.Next, k)
    tail.Next = nil
    cur = head
    next = cur.Next
    for {
        cur.Next = pre
        pre = cur
        if next == nil {
            break
        }
        cur = next
        next = cur.Next
    }
    return cur
}
```
