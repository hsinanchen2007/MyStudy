### 解题思路
先利用双指针找到链表的中心，断开链表，反转后半部分，最后再重新拼接

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
func reorderList(_ head: ListNode?) {
    var a = head
    var b = head?.next?.next
    
    guard b != nil else { return }
    
    while b != nil {
        a = a?.next
        b = b?.next?.next
    }
    
//c 为后半段链表的开始节点
    let c = a?.next

//断开链表
    a?.next = nil
     
//反转后半部分
    var pre = c
    let current = c
    while current?.next != nil {
        let next = current?.next
        
        current?.next = next?.next
        next?.next = pre
        
        pre = next
    }
    
//按要求重新拼接
    var i = head
    var j = pre
    var dummy: ListNode? = ListNode(-1)
    
    while i != nil || j != nil {
        if i != nil {
            dummy?.next = i
            dummy = dummy?.next

            i = i?.next
        }
        
        if j != nil {
            dummy?.next = j
            dummy = dummy?.next

            j = j?.next
        }
    }
}
}
```