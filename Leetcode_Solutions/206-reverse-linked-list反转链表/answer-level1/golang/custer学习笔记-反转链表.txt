# 方法一: 迭代方法
学习自
- [https://leetcode-cn.com/problems/two-sum/solution/0msfan-zhuan-lian-biao-de-go-shi-xian-by-elliotxx/](https://leetcode-cn.com/problems/two-sum/solution/0msfan-zhuan-lian-biao-de-go-shi-xian-by-elliotxx/)
- [https://github.com/aQuaYi/LeetCode-in-Go/blob/master/Algorithms/0206.reverse-linked-list/reverse-linked-list.go](https://github.com/aQuaYi/LeetCode-in-Go/blob/master/Algorithms/0206.reverse-linked-list/reverse-linked-list.go)

```go
func reverseList1(head *ListNode) *ListNode {
    var pre *ListNode = nil // prev 是所有已经逆转的节点的head
    for head != nil {       // head 是下一个被逆转的节点
        next := head.Next // 先保存下一个节点，让next指向head.Next
        head.Next = pre   // 当前节点指向上一个节点，完成逆转
        pre = head        // 当前节点变为上一个节点，prev为已被逆转节点的head
        head = next       // 让head指向下一个被逆转的节点
    }
    return pre
}
```

# 简化
[https://github.com/NachtZ/leetcode/blob/master/206.%20Reverse%20Linked%20List.go](https://github.com/NachtZ/leetcode/blob/master/206.%20Reverse%20Linked%20List.go)

```go
func reverseList2(head *ListNode) *ListNode {
    var newHead ListNode
    for head != nil {
        newHead.Next, head.Next, head = head, newHead.Next, head.Next
    }
    return newHead.Next
}
```

# 方法二：递归方法，原地反转链表

```go
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