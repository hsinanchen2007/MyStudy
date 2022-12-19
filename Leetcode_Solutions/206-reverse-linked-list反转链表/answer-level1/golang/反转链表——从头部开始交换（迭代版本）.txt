### 解题思路
反转链表主要有两种思路：
- 从前向后反转的迭代实现（当然也能原模原样地写成递归）
- 从后向前开始逆转指针方向的递归方法

下面是迭代方法的实现，清晰易懂
- 先临时保存`cur.Next`
- 再将`cur.Next`指向`pre`
- `pre`向前移动（`pre = cur`）
- `cur`向前移动（`cur = tmp`）

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
    // 边界
    if head == nil || head.Next == nil {return head}
    
    // 迭代
    var pre, tmp *ListNode
    cur := head
    for cur != nil {
        tmp = cur.Next
        cur.Next = pre
        pre = cur
        cur = tmp
    } 
    // 最后pre就是新的head
    return pre
}
```