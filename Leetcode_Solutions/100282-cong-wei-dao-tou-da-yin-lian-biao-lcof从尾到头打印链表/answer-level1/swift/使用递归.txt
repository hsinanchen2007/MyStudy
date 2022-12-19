达到反向执行的效果可以使用递归

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
    func reversePrint(_ head: ListNode?) -> [Int] {
    guard var head = head else { return [] }
    guard head.next != nil else { return [head.val] }
    var tmp = [Int]()
    
    func recur(_ node: ListNode?) {
        guard let node = node else { return }
        recur(node.next)
        tmp.append(node.val)
    }
    
    recur(head)
    
    return tmp
    }
}
```