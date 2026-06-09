```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None:
            return None
        if head.next==None:
            return head
        pre = head
        pro = head.next
        pre_val = -999
        while pro:
            if  pre.val==pro.val:
                pre_val = pre.val
                if pre==head:
                    head = pro.next
                    t = head
                    pre = head 
                    if head:
                        pro = head.next
                    else:
                        break
                else:
                    t.next = pro.next
                    pre = pro.next
                    if pre:
                        pro = pre.next
                    else:
                        break
            elif pre.val==pre_val:
                if pre==head:
                    head = pro
                    t = head
                    pre = head 
                    if head:
                        pro = head.next
                    else:
                        break
                else:
                    t.next = pro
                    pre = pro
                    if pre:
                        pro = pre.next
                    else:
                        break
            else:
                t = pre
                pre = pro
                pro = pro.next
        if pre:        
            if  pre.val==pre_val:
                if pre==head:
                    head = pro
                else:
                    t.next = pro
        return head
                    
                    
                
        
        
```
