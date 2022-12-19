### 解题思路
* 这道题目是链表题目，所以无法使用数组随机访问的特点，最好能够一次性访问链表中的数据
* 这道题目是找到下一个更大的数，所以在这里找到一个单调栈，所有入栈的数字都会比前一个数字更小，否则将会出栈，找到该数之前所有比该数小的数的结果
* 每次访问链表时，先进行栈顶判断，如果栈顶元素小于链表数据，则出栈，否则添加入栈，结果列表添加结果0
* 出栈数据时替换结果列表中的0，这时缺少结果列表中的索引，于是添加存储索引数据
* 总体这道题目还是保持栈的统一特性，使其具有单调性，类似题目需要尽量转换为单调性

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
    func nextLargerNodes(_ head: ListNode?) -> [Int] {
        var stack = [(Int,Int)]()
        var node = head
        var index = 0
        var result = [Int]()
        while let n = node {
            while let last = stack.last, last.0 < n.val {
                    stack.removeLast()
                    result[last.1] = n.val
            }
            stack.append((n.val,index))
            index += 1
            result.append(0)
            node = n.next
        }
        return result
    }
}
```