这段话只是表达了我对解法的赞美，没有干货，可以直接跳过看代码。

这道题我挣扎了四天一直，有想法，觉得很简单，但总是写不对。
下面的解法是参考大神的版本，原本我的思路其实也是如此，只是代码表达有些问题。归根到底只想说提高算法只能靠多练习，多思考啊。

```swift []
class Solution {
    func deleteDuplicates(_ head: ListNode?) -> ListNode? {
        let head_ = ListNode.init(-1)
        head_.next = head

        var slow: ListNode? = nil
        var fast: ListNode? = head_

        while fast != nil {
            slow = fast
            fast = fast?.next
            while fast != nil, fast?.next != nil, fast?.val == fast?.next?.val {
                let value = fast?.val
                while fast != nil, fast?.val == value {
                    fast = fast?.next
                }
                slow?.next = fast
            }
        }

        return head_.next
    }
}
```
```python []
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        head_ = ListNode(-1)
        head_.next = head
        
        slow = None
        fast = head_
        
        while fast is not None:
            slow = fast
            fast = fast.next
            while fast is not None and fast.next is not None and fast.val == fast.next.val:
                value = fast.val
                while fast is not None and fast.val == value:
                    fast = fast.next
                slow.next = fast
        return head_.next
```
