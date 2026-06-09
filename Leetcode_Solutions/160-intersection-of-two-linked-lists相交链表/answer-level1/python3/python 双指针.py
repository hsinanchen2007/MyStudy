找交叉点--->两个指针相等--->消除两个指针的路程差--->AB两个链表的总长度是相同的，于是a指针跑完再去跑一下b链表，b指针跑完再去跑一下a链表，
由于两个指针同时在动，只要它们跑的路程相同，相遇点就是交叉点。

```
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        pa = headA
        pb = headB
        while pa != pb:
            pa = headB if not pa else pa.next
            pb = headA if not pb else pb.next
        return pa
```
