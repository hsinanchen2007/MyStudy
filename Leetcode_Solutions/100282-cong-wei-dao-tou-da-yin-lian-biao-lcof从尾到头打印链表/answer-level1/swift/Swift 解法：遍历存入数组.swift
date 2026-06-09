思路：遍历链表，同时将元素值放在数组首位

```swift
public class ListNode {
     public var val: Int
     public var next: ListNode?
     public init(_ val: Int) {
         self.val = val
         self.next = nil
     }
}

class Solution {
    func reversePrint(_ head: ListNode?) -> [Int] {
        guard let value = head?.val else {
            return []
        }
        var arr:[Int] = [value]
        var nextNode = head?.next
        while nextNode != nil { // 结束标志
            arr.insert(nextNode!.val, at: 0) // 每次放在数组首位
            nextNode = nextNode?.next
        }
        return arr
    }
}
```