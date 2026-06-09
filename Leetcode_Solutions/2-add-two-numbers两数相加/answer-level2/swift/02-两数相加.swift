### 解题思路
简单的思路就是保存进位，然后一直将两个链表一直循环完直到进位也为0。

### 代码

```swift
class Solution {
    func addTwoNumbers(_ A: ListNode?, _ B: ListNode?) -> ListNode? {
        if A == nil && B == nil {
            return nil
        }
    
        // 两个链表不都为空
        var l1 = A
        var l2 = B

        var prev = ListNode(0)
        var tail = prev
        var flag = 0

        while l1?.val != nil || l2?.val != nil || flag == 1 {
            var num1 = l1?.val ?? 0
            var num2 = l2?.val ?? 0
            var num = num1 + num2 + flag

            if num < 10 {
                flag = 0
            } else {
                num = num % 10
                flag = 1
            }

            tail.next = ListNode(num)
            tail = tail.next!
            l1 = l1?.next
            l2 = l2?.next
        }
        
        return prev.next

    }
}
```