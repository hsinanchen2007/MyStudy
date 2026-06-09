

要删除 倒数第N个节点，只需要找到倒数第N+1个节点就可以了

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
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        var i = head
        var k = head
        
//使i和开的距离为N
        (0..<n).forEach { _ in k = k?.next }
        

        if k?.next != nil {
//使i k 距离为N+1，这样删除i.next就可以了
            k = k?.next
        } else {
//考虑要删除head的情况
            let x = i?.next
            i?.next = nil
            return x
        }
        
//k == nil时， 删除i.next
        while k != nil {
            i = i?.next
            k = k?.next
        }
        
//删除i.next
        let z = i?.next
        i?.next = z?.next
        z?.next = nil
        
        return head
    }
}
```