```swift []
class Solution {
func partition(_ head: ListNode?, _ x: Int) -> ListNode? {
        var beforeHead: ListNode?
        var before: ListNode?
        var afterHead: ListNode?
        var after: ListNode?
//        var joinHead: ListNode?
//        var join: ListNode?
        
        var cur: ListNode? = head
        while var tmp = cur {
            
            if tmp.val < x {
                if beforeHead == nil {
                    beforeHead = tmp
                    before = tmp
                } else {
                    before?.next = tmp
                    before = tmp
                }
//            } else if tmp.val == x {
//                if joinHead == nil {
//                    joinHead = tmp
//                    join = tmp
//                } else {
//                    join?.next = tmp
//                    join = tmp
//                }
            } else {
                if afterHead == nil {
                    afterHead = tmp
                    after = tmp
                } else {
                    after?.next = tmp
                    after = tmp
                }
            }
            
            cur = cur?.next
        }
        
        before?.next = afterHead
        after?.next = nil
        return beforeHead == nil ? afterHead : beforeHead
        
    }
        
}
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
