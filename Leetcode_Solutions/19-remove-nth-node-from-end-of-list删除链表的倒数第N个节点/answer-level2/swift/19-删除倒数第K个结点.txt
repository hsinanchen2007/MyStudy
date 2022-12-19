### 解题思路
由于是倒数第k个结点，所以先让一个结点先走K步即可。因为要删除第K个结点，所以要获得第K-1个结点，然后利用k-1.next.next来删除K结点。

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
    func removeNthFromEnd(_ A: ListNode?, _ n: Int) -> ListNode? {
        var prev: ListNode? = ListNode(0)
        prev?.next = A
        var low = prev
        var high = prev
        
        for _ in 0..<n {
            high = high?.next
        }

        while high?.next != nil {
            low = low?.next
            high = high?.next
        }

        low?.next = low?.next?.next
        
        return prev?.next

    }
}
```