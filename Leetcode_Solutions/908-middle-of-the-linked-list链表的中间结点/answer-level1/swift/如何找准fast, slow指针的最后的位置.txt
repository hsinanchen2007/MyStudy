### 解题思路

#### 注意点
* 偶数的时候取中间第二个节点
* 奇数的时候直接区中间节点

#### 如何才能是slow精准的落在中间点
为了能逻辑上清晰精准的判断中间节点 前面移动的时候保证fast.next 和fast.next.next都不为空的时候移动
最后得出两种情况
* 奇数点的时候 fast 精准落到最后一个点,  slow刚好是中间点
* 偶数点的时候 fast 精准落到倒数第二个点, slow刚好是中间点第一个点

下一步 如果fast.next 不为空的时候 表示链表是偶数个点 slow再移动一步即可到中间第二个点




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
    func middleNode(_ head: ListNode?) -> ListNode? {
        var slow = head
        var fast = head
    
        // 1 2 3 4 5 
        // 1 2 3 4 5 6
        // 如果是奇数个节点 fast可以走到最后一个节点
        // 如果是偶数个节点 fast可以走到倒数第二个节点
        while fast?.next != nil && fast?.next?.next != nil {
            slow = slow?.next
            fast = fast?.next?.next
        }
        //
        // fast?.next != nil 表示有偶数个节点
        // 偶数的时候slow再走一步 走到中间第二个值
        if fast?.next != nil {
            slow = slow?.next
        }
    
        return slow

    }
}
```