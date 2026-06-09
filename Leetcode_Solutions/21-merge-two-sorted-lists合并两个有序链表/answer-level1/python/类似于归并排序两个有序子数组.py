```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None and l2 is None:
            return None
        if l1 is None:
            return l2
        if l2 is None:
            return l1        
        
        # 确定头结点
        dummy = ListNode(0)
        if l1.val <= l2.val:
            dummy.next = l1
            pre = l1
            l1 = l1.next
        else:
            dummy.next = l2
            pre = l2
            l2 = l2.next
        
        # 两个指针，类似于归并合并有序数组
        while l1!= None or l2!= None:
            if l1!= None and l2!= None:
                if l1.val <= l2.val:
                    pre.next = l1
                    pre = l1
                    l1 = l1.next
                else:
                    pre.next = l2
                    pre = l2
                    l2 = l2.next
            elif l1 == None and l2!= None:
                pre.next = l2
                pre = l2
                l2 = l2.next
                
            else: 
                pre.next = l1
                pre = l1
                l1 = l1.next
               
        return dummy.next
```