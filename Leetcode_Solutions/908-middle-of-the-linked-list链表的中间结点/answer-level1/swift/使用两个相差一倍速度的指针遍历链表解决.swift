### 解题思路
一个指针1倍速前进
另一个指针2倍速前进

当快指针为空时结束。此时慢指针正好是中间元素。

这里也一样需要借助dumy哨兵解决。

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
    func middleNode(_ head: ListNode?) -> ListNode? {
        var dumy = ListNode(-1)
        dumy.next = head

        var fast : ListNode? = dumy
        var slow : ListNode? = dumy

        while fast != nil {
            fast = fast?.next?.next
            slow = slow?.next
        }
        return slow
    }
}
```