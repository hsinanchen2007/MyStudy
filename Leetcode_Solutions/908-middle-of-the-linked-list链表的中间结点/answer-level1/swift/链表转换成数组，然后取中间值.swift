### 解题思路
链表转换成数组，然后取中间值

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
        
        var node = head
        var array = Array<ListNode>.init()
        array.append(node!)
        while node!.next != nil {
            node = node!.next
            array.append(node!)
        }
        
        if array.count % 2 == 0 {
            let index = array.count / 2
            return array[index]
        }
        
        let index = (array.count - 1) / 2
        return array[index]
    }
}
```