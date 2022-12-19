根据题意，我们需要反转[m, n]范围的节点。由此，我们需要将链表分为左中右三段。基于此，我们需要记录左子链表的尾节点，中子链表的首尾节点及右子链表的头结点，当我们完成对中子链表的反转后，连接三个子链表即可。
**注意点**：我们需要注意的是连接过程中左子链表尾节点为空的问题，也就是`m=1`的问题
**思路**：设置四个变量，`var leftTail, midHead, midTail, rightHead *ListNode`用于连接子链。设置`var pre, cur *ListNode`作为反转链表的节点。
1. 不断的往前移动`pre`和`cur`使得`cur`指向第m个节点，然后保存左子链表的尾节点`leftTail = pre`和中子链表的尾节点`midTail = cur`，然后开始反转直至`cur`指向第m+1个节点。
2. 当`cur`指向第m+1个节点时，保存中子链表的头结点`midHead = pre`和右子链表的头结点`rightHead = cur`。
3. 连接三个子链表，**需要注意`leftTail`为空的问题，避免出现空指针异常**

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    if m == n {
        return head
    }
    var leftHead, rightHead *ListNode
    var midHead, midTail *ListNode
    var pre, cur *ListNode
    cur = head
    for i := 1; i <= n ; i++ {
        if i < m {
            pre, cur = cur, cur.Next
        } else if i >= m && i <= n {
            if i == m {
                leftHead = pre
                midTail = cur
            } else if i == n {
                rightHead = cur.Next
                midHead = cur
            }
            next := cur.Next
            cur.Next = pre
            pre, cur = cur, next
        }
    }
    if leftHead == nil {
        head = midHead
    } else {
        leftHead.Next = midHead
    }
    midTail.Next = rightHead

    return head
}
```