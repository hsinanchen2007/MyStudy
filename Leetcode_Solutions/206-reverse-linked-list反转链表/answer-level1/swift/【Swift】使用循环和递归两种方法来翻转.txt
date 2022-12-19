### 递归和循环反正

### 递归翻转
```
// 递归翻转
func reverseList(_ head: ListNode?) -> ListNode? {
    if head == nil || head!.next == nil {
        return head
    }
    var temp = reverseList(head!.next)
    head!.next?.next = head
    head?.next = nil
    return temp
}
```

### 循环反转
```
// 循环翻转
func reverseList(_ head: ListNode?) -> ListNode? {
    if head == nil || head!.next == nil {
        return head
    }
    var head = head
    var previous: ListNode?

    while head != nil {
        let temp = head
        head = head?.next
        temp?.next = previous
        previous = temp
    }
    return previous
}
```
