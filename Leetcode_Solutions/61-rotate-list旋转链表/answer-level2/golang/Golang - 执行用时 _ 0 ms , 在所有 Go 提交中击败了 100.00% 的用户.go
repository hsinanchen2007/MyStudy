### 解题思路
1. 遍历一遍linkedlist得出length和tail
2. length - k % length 找到需要截断linkedlist的位置，截成前半段list1和后半段list2
3. 重新拼接链表 -> list2+list1，return newHead
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
    if head == nil || head.Next == nil {
        return head
    }
    length := 0
    current := head
    tail := head
    for current != nil {
        if current.Next == nil {
            tail = current
        }
        current = current.Next
        length++
    }
    current = head
    steps := k % length
    if steps == 0 {
        return head
    }
    pos := length - steps
    for pos > 1 {
        current = current.Next
        pos--
    }
    newHead := current.Next
    tail.Next = head
    current.Next = nil
    return newHead
}
```

### 复杂度分析
时间复杂度：O(n) linkedlist的node数量
空间复杂度：O(1) 只需要常数数量的临时变量