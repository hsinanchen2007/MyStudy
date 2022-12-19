1.hash实现
```
func hasCycle(head *ListNode) bool {
    nodeExist := make(map[*ListNode]int)
    cur := head
    for cur != nil {
        if _, exist := nodeExist[cur]; exist {
            return true
        }
        nodeExist[cur] = 1
        cur = cur.Next
    }
    return false
}
```

2.快慢指针
```
func hasCycle(head *ListNode) bool {
    if head == nil || head.Next ==  nil {
        return false
    }
    
    slow, fast := head, head.Next
    for slow != fast {
        if fast == nil || fast.Next == nil {
            return false
        }
        slow = slow.Next
        fast = fast.Next.Next
    }
    return true
}
```
