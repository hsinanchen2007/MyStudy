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
        ans = ListNode(0)
        p = ans
        flag = False
        while head != None:
            if head.next != None and head.val == head.next.val:
                flag = True
            elif flag:
                flag = False
            else:
                p.next = head
                head = head.next
                p = p.next
                p.next = None
                continue
            head = head.next
                
        return ans.next
```
