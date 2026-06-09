### 解题思路
官方题解用新的头指针来指向偶数链表，最后再拼接。 感觉不算原地处理。 
我的做法是
1.先找到尾节点和链表长度
2.遍历链表，偶数节点放到尾节点后面，奇数节点不动，遍历完链表长度时结束

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    //找到尾节点
    tail := head
    length := 0
    for tail.Next != nil {
        length++
        tail = tail.Next
    }

    //长度为1，2，不用转
    if length < 2 {
        return head
    }

    curr := head
    res := &ListNode{
        Next: head,
    }
    pre := res
    i := 1
    for curr != nil && i <= length+1 { //限定i的次数，避免一直向后遍历
        if i % 2 == 0 { //偶数节点，放到尾部，prev节点指向下一个
            pre.Next = curr.Next
            curr.Next = nil
            tail.Next = curr
            tail = tail.Next
            curr = pre.Next
        } else {
            pre = curr
            curr = curr.Next
        }
        i++
    }

    return res.Next
}
```