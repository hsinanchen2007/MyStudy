### 解题思路
1. 将原链表形成一个闭环
2. 查找偏移量 n - k % n - 1,这里运算优先级不要加括号
3. 查找的闭环的末尾节点，并将节点断开

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    if nil == head || nil == head.Next {
        return head
    }
    var n int = 0
    // 找到原链表末尾节点并将其指向头节点
    oldTail := head
    for n = 1; nil != oldTail.Next; n++ {
        oldTail = oldTail.Next
    }
    // 将旧链表尾节点指向原链表头部,形成一个闭环
    oldTail.Next = head
    newTail := head
    // 找到新链表的头部
    for i := 0; i < n - k % n - 1; i++ {
        newTail = newTail.Next
    }
    newHead := newTail.Next
    newTail.Next = nil
    return newHead
}
```