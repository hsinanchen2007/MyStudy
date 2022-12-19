```
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head is None or head.next is None:
            return head
        #找到中间点
        slow,fast = head,head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        #以中间点为界，将链表断开为两部分
        cur,pre = slow.next,None
        slow.next = None
        #将后半部分进行链表倒置(返回的pre为倒置部分的表头)
        while cur:
            nex = cur.next
            cur.next = pre
            pre = cur
            cur = nex
        #将新的两个链表进行重新链接
        cur1, cur2 = head, pre
        while cur2:
            nex1, nex2 = cur1.next, cur2.next
            cur1.next = cur2
            cur2.next = nex1
            cur1, cur2 = nex1, nex2
        return head 
```
