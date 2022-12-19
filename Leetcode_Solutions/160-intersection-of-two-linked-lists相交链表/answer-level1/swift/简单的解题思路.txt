看了一些解题思路都写得不错，现在我也将我的思路演绎过程展示出来作参考。
两个链表有相同的部分如果将两个链表重新排序则可以组成有环链表。两个指针分别指向两个链表head，并向后遍历，当指向null时重新指向另一个链表head。这个过程如图所示，在有环的链表中两个指正最终会相遇，也就是同时指向共同的部分的其实节点。
![IMG_6054.jpg](https://pic.leetcode-cn.com/0657bdf0abb7bf263bda52fb5946d468d4b193bfb6a4c291577befeb3df2fe69-file_1574686502454)


```python []
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        head1 = headA
        head2 = headB
        while head1 != head2:
            head1 = headB if head1 is None else head1.next
            head2 = headA if head2 is None else head2.next
        return head1
```
```swift []
class Solution {
    func getIntersectionNode(headA: ListNode, headB: ListNode) -> ListNode? {
        var head1: ListNode? = headA, head2: ListNode? = headB
        while head1 != head2 {
            head1 = head1 != nil ? head1?.next : headB
            head2 = head2 != nil ? head2?.next : headA
        }
        return head1
    }
}
```
