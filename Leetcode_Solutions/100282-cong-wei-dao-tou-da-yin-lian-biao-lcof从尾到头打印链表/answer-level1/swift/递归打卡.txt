
``` swift
class Solution {
    func reversePrint(_ head: ListNode?) -> [Int] {
        guard let head = head else {
            return []
        }
        var result = reversePrint(head.next)
        result.append(head.val)
        return result
    }
}
```

