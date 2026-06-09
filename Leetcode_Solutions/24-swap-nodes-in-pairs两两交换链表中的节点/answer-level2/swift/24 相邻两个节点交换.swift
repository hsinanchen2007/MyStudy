### 解题思路

创建一个hd,hd.next保存当前head的。作为返回使用。
1、创建一个中间变量pre来作为交换使用，只有交换后pre的next或者pre 会为空。
2、while中循环 创建 两个临时变量。a 、b 作用交换。
    
第一次交换，将pre中的next的对象给到a。把pre.next.next的对象给到b。
实际上理解为取出了第一个元素，和第二个元素。
因为第一个元素的next是指向第二个元素。要交换就是改变pre.next的指向就好了。
将pre.next改成b，此时a没有next指向了。再将a的next指向原来b.next的对象。
此时第三个元素的被a指向了。但是a、b还没有相互指向。此时的b.next就要指向a就可以了。  
再将a赋值个pre。那就可以进行第二个循环了。依此类推。
知道最后pre.next没有指向了。循环结束.
此时要返回的是最开始的hd。

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
      func swapPairs(_ head: ListNode?) -> ListNode? {
        let hd = ListNode.init(-1)
        hd.next = head
        var pre :ListNode? = hd
        while pre?.next != nil,pre?.next?.next != nil {
            let a = pre?.next
            let b = pre?.next?.next
            pre?.next = b
            a?.next = b?.next
            b?.next = a
            pre = a
        }
        return hd.next
    }

}
```