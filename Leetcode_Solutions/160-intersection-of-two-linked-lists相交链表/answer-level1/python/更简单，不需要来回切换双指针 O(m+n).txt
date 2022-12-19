# 思路：
两个长度不一的链表找相交点。
如果两个指针能从距离各自结尾长度相同的点开始，一步一步比较并向后移，必然能找到有没有相交点。
因为二者如果相交，后面必然是相同的长度

所以只需要找到长的链表，让其指针先走k步（k为二者长度之差，二者则会同时到达终点），然后两个指针同时移并比较

那么求距离之差k，自然加2个计数器

```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB:
            return
        
        curr1 = headA
        curr2 = headB
        c1 = 0
        while curr1 and curr2:
            curr1 = curr1.next
            curr2 = curr2.next
            c1 += 1
            
        c2 = c1
        longhead = headA
        shorthead = headB
        if curr1:
            longhead = headA
            shorthead = headB
            while curr1:
                curr1 = curr1.next
                c2 += 1
        if curr2:
            longhead = headB
            shorthead = headA
            while curr2:
                curr2 = curr2.next
                c2 += 1
                
        # k为两个链表的长度差
        k = c2 - c1
        while k:
            longhead = longhead.next
            k -= 1
        
        while longhead and shorthead:
            if longhead is shorthead:
                return longhead
            longhead = longhead.next
            shorthead = shorthead.next
```
