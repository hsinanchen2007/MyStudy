### 解题思路
首先确定一个为空的头结点，然后比较两个链表，用尾插法选择小的加入到新的头结点中即可。

### 代码

```swift
class Solution {
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        // 创建新的头结点
        let prev: ListNode? = ListNode.init(0)
        
        // 用尾插法来建立链表
        var tail = prev

        // 因为Swift的方法的参数都是不可变的，所以重新用两个参数来代替l1和l2
        var first = l1
        var second = l2
        
        // 同时扫描l1与l2
        while first != nil && second != nil {
            if first!.val < second!.val {
                tail?.next = first
                first = first?.next
                tail = tail?.next
            } else {
                tail?.next = second
                second = second?.next
                tail = tail?.next
            }
        }
        
        // 将l1或者l2剩余的添加到链表中
        if first != nil {
            tail?.next = first
        }
        
        if second != nil {
            tail?.next = second
        }
        
        // 题目不含头结点,返回prev.next
        return prev?.next
    }
    
}
```