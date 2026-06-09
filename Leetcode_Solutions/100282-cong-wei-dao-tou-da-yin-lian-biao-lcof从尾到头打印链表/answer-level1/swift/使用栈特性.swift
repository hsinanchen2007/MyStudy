1. 遍历链表, 放入数组中
2. 遍历数组, 根据数组 index 查找快, 根据 (res.count - 1 - index) 从后开始找元素, 倒序加入数组

时间复杂度: O(n)
空间复杂度: O(n)

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
        var stackArr = [Int]()
        
        while let next = head.next {
            stackArr.append(head.val)
            head = next
        }
        // add the last node
        stackArr.append(head.val)
        
        var res = [Int]()
        for index in 0..<stackArr.count {
            res.append(stackArr[stackArr.count-1-index])
        }
        return res
    }
}
```