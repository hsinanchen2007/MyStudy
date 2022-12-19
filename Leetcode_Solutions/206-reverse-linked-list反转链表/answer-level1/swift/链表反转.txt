### 解题思路
此处撰写解题思路

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
    func reverseList(_ head: ListNode?) -> ListNode? {
        var headFirstPointed = head?.next
        var resultFirstPointed = head
        resultFirstPointed?.next = nil
    
        while true {
            print(headFirstPointed?.val ?? 0)
            if headFirstPointed == nil {
                break
            }
        
            let node = ListNode.init(headFirstPointed!.val) 
            node.next = resultFirstPointed
            resultFirstPointed = node
            headFirstPointed = headFirstPointed?.next
        }
    
    
        return resultFirstPointed
    }
}
```
