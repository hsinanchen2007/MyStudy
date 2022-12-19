```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        #优化为在找中点的同时反转前一半链表，这样只需遍历n/2(找中点+反转前一半)+n/2(比较) = n次
        if head == None or head.next == None: return True
        pre,slow,fast = None,head,head
        while(fast and fast.next):
            rear,fast = slow.next,fast.next.next
            slow.next = pre
            pre = slow
            slow =rear
        if fast != None:   #说明链为奇数数
            slow = slow.next
        while(pre and slow):
            if pre.val != slow.val:
                return False
            pre,slow = pre.next,slow.next 
        return True
        
        
        
        
        #我初次的做法是找到终点后反转后面的一半链表，但其实就遍历了n/2(找中点)+n/2(反转后一半链表)+n/2(比较) = (3/2)n次
#        if head ==None or head.next == None: return True
#        slow,fast = head,head
#        while fast.next and fast.next.next:
#            slow,fast = slow.next,fast.next.next
#        mid = slow
#        slow,fast = head,mid.next
#        mid.next = None
        
#        pre,cur = None,fast
#        while cur:
#            tmp = cur.next
#            cur.next = pre
#            pre = cur
#            cur = tmp
#        while pre and slow:
#            if pre.val != slow.val:
#                return False
#            pre,slow = pre.next,slow.next
#        return True
            
```
