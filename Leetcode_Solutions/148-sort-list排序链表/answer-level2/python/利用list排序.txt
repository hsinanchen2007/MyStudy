【思路】先将head中的val值挨个放在L中，然后对L从小到大排序，再将L中得值从前往后挨个取出链在p后面

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        L=[]
        p=head
        result=p 
        while head:
            L.append(head.val)  
            head=head.next
        L.sort()   #对L从小到大排序
       #L=sorted(L)
        for i in L:
            p.val=i
            p=p.next
        return result
        
```
