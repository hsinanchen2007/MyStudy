### 解题思路
1 组成循环链表
2 从head位置开始迭代，迭代 len-(k%len) 次，即得到尾结点和新的头节点
3 将尾结点Next置为空，返回新的头结点

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
    //特殊情况
    if head == nil || head.Next ==nil {
        return head
    }
    //组成循环链表
    //从head数, length-k 的位置断开
    var (
        len int
        newTail *ListNode
    )
    for i := head; i != nil ; {
        len ++ 
        if i.Next == nil {
            i.Next = head
            break
        }
        i = i.Next
    }
    k = k % len
    for i := 0; i< len-k ;i++ {
        newTail = head
        head = head.Next
    }
    
    newTail.Next = nil
    return head
}
```