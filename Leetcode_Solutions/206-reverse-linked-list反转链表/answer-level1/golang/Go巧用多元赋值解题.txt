**这道题目的关键就在于利用一个临时的节点来保存下一次的当前节点**

一开始没办法理解多元赋值的巧妙的，可以先看解法1，解法2就是在解法1的基础上妙用了go的多元赋值

解法1：

```golang []

func reverseList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    var prev *ListNode
    var tmpNode *ListNode
    var cur = head
    for cur != nil {
        tmpNode = cur.Next
        cur.Next = prev
        prev = cur
        cur = tmpNode
    }
    return prev
    
}

```

解法2：

```golang []

func reverseList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    var prev *ListNode
    var cur = head
    for cur != nil {
        cur.Next, prev, cur = prev, cur, cur.Next
    }
    return prev
    
}

```