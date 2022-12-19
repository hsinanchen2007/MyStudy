### 解题思路
头插法变形

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
    func reverseKGroup(_ head: ListNode?, _ k: Int) -> ListNode? {
        guard k > 1 else { return head }
        
        var dummy: ListNode? = ListNode(-1)
        dummy?.next = head
        
        var current = dummy?.next
        var flag = dummy
        
        var newHead: ListNode? = nil
        
        loop: while true {
//检查剩余的节点数，如果小于K，则反转结束
            for _ in 0..<k {
                flag = flag?.next
                if flag == nil {
                    break loop
                }
            }
            
//获取反转之后的head
            if newHead == nil {
                newHead = flag
            }
            
//反转当前的一组节点
            (0..<k - 1).forEach { _ in
                let next = current?.next
                current?.next = next?.next
                
                next?.next = dummy?.next
                dummy?.next = next
            }

//下一组待反转节点的相关指针 
            dummy = current
            current = dummy?.next
            flag = dummy
        }

        return newHead
    }
}

```