### 解题思路
此题正常就是相加进位逻辑
有坑的地方 
最后一个进位要保留，不能丢弃了



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
     func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil {
            return l2
        }
        sumNode(l1, l2, nil, 0)
        return l1
    }

    func sumNode(_ l1: ListNode?, _ l2: ListNode?, _ node: ListNode?, _ sum: Int) {
        if l1 == nil && l2 == nil  {
            if sum == 0 {
                return
            }
            let a = ListNode(sum);
            node?.next = a
            return
        }
        
        var s = sum;
        var tmp:ListNode? = nil;
        if l1 != nil {
            s += l1!.val
            tmp = l1
        }
        
        if l2 != nil {
            s += l2!.val
            if tmp == nil {
                tmp = l2
            }
        }
        
        tmp?.val = s%10
        s=s/10
        
        if node != nil {
            node!.next = tmp
        }
        
        sumNode(l1?.next, l2?.next, tmp, s)
    }
}
```