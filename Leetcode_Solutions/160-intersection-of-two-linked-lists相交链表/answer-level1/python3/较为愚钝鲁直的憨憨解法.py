思路：排除一些特定的测试用例情况，把A和B链表长度确定。
因为单链表后半段相同，所以分别循环向后找到相同的，返回
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB: return
        lenA,lenB,i=0,0,0
        listna,listnb=headA,headB
        while listna:
            listna=listna.next
            lenA+=1
        while listnb:
            listnb=listnb.next
            lenB+=1
        if lenA==lenB==1: 
            if headA==headB: return headA
            else: return
        if lenA<lenB:
            while i<lenB-lenA:
                headB=headB.next
                i+=1
        if lenA>lenB:
            while i<lenA-lenB:
                headA=headA.next
                i+=1
        while headA!=headB:
            headA,headB=headA.next,headB.next
        return headB
        
        

```
