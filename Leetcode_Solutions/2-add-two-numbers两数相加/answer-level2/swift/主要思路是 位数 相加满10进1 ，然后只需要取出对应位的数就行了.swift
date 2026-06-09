### 解题思路
主要思路是 位数 相加满10进1 ，然后只需要取出对应位的数就行了

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
        if l1 != nil && l2 != nil{
            var node1 = l1!
            var node2 = l2!
            while(true){
                add(node1,node2.val)
                if node2.next == nil{
                    break
                }
                else{
                    node2 = node2.next!
                    if node1.next == nil{
                        node1.next = ListNode(0)
                    }
                    node1 = node1.next!
                }           
            }
            return l1
        }
        else{
            return nil
        }      
    }
    public func add(_ node:ListNode,_ val:Int){
        let sum = node.val + val
        if sum >= 10{
            node.val = sum - 10
            if node.next == nil{
                node.next = ListNode(1)
            }
            else{
                add(node.next!,1)
            }
        }
        else{
            node.val = sum
        }
    }
}


```