
![image.png](https://pic.leetcode-cn.com/569db47d8fdc3980a4fbad0a0998d40309a58a5b7f1cf17788fec8fcc3411ef4-image.png)

方法一：迭代方法，原地反转链表（0ms）
```
func reverseList(head *ListNode) *ListNode {    // 迭代方法，原地反转链表
    var pre *ListNode = nil
    for head!=nil {
        next := head.Next   // 先存下下一个节点，不然一会就没了
        head.Next = pre     // 当前节点指向上一个节点
        pre = head          
        head = next
    }
    return pre
}
```

方法二：递归方法，原地反转链表（4ms）
```
func reverse(pre,cur *ListNode) *ListNode {
    if cur == nil {
        return pre
    }
    head := reverse(cur, cur.Next)
    cur.Next = pre
    return head
}

func reverseList(head *ListNode) *ListNode {    // 递归方法，原地反转链表
    return reverse(nil, head)
}
```