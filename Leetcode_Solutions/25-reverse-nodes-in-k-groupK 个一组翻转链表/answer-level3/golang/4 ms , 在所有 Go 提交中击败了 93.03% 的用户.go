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
func reverseKGroup(head *ListNode, k int) *ListNode {
    // 判断链表是否已经为空
    if head == nil {
        return nil
    }

    // 查找下一组反转区间，并判断反转区间是否合法
    a, b := head, head
    for i := 0; i<k; i++ {
        if b == nil {
            return head
        }
        b = b.Next
    }

    // 将区间a, b的节点反转
    newHead := recverse(a, b)
    // 进入子问题，进行下一组递归反转
    a.Next = reverseKGroup(b, k)
    return newHead
}

// 反转[a,b)区间的节点
func recverse(a *ListNode, b *ListNode) *ListNode {
    var pre *ListNode = nil
    cur := a
    nxt := a
    for b != cur {
        // 1.保存前进方向
        nxt = cur.Next
        // 2.当前节点的下一节点指向前驱节点
        cur.Next = pre
        // 3.更新前驱节点
        pre = cur
        // 4.更新当前状态
        cur = nxt
    }
    return pre
}









```