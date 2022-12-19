### 解题思路

可选链与位左移运算符

执行用时 :0 ms, 在所有 Swift 提交中击败了100.00%的用户
内存消耗 :20.8 MB, 在所有 Swift 提交中击败了5.26%的用户

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
    func getDecimalValue(_ head: ListNode?) -> Int {
        
        //指向表头
        var node = head
        //定义返回值
        var ans = 0
        
        //遍历链表直至表尾
        while node != nil {
            
            //将每个节点的值添加进返回
            if let value = node?.val {
                ans += value
            }
            
            //如果还有下一个节点，就讲当前保存的返回值左移一位
            if let next = node?.next {
                ans = ans << 1
                node = next //指向下一个节点
            } else {
                node = nil
            }

        }

        return ans
    }
}

```