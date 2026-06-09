### 解题思路

需要看是否在头部，头部的处理和后面不一样

- 先移除头部的匹配项
- 灾移除后面的匹配项

这个题目说节点互补相同，其实可以匹配到之后就 return，
注意：下面是通用处理方法实现，可以实现存在多个相同值节点的移除操作。

### 代码

```swift
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
        func deleteNode(_ head: ListNode?, _ val: Int) -> ListNode? {
        var head = head
        while head != nil && head?.val == val {
            head = head?.next
        }

        var prev = head
        while prev?.next != nil {
            if prev?.next?.val == val {
                prev?.next = prev?.next?.next
            } else {
                prev = prev?.next
            }
        }

        return head
    }
}
```