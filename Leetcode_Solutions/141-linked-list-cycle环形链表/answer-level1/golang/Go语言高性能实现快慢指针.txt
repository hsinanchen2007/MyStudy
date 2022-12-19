快慢指针相遇则有环
```
func hasCycle(head *ListNode) bool {
    // 只有两个及以上节点才能出现环
    if head == nil || head.Next == nil {
        return false
    }

    // 快慢指针
    slow := head
    fast := head.Next

    for fast != nil {
        // 如果相遇了则有环
        if fast == slow {
            return true
        }

        // 慢指针跑一步
        slow = slow.Next

        // 注意快指针跑两步，有可能是最后一个节点
        // 这时候就会出现空指针异常，这里判断下是不是最后一个节点
        if fast.Next == nil {
            return false
        }

        // 快指针走两步
        fast = fast.Next.Next
    }

    return false
}
```
