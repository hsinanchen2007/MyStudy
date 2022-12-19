### 方法一：双指针
#### 代码实现：
```golang
func reverseList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
        
    var pre *ListNode
    cur := head 
    for cur != nil {
        cur.Next, pre, cur =  pre, cur, cur.Next
    }

    return pre
}
```

### 方法二：递归迭代
#### 代码实现：
```golang
func reverseList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }

    cur := reverseList(head.Next)
    head.Next.Next = head
    head.Next = nil

    return cur
}
```
