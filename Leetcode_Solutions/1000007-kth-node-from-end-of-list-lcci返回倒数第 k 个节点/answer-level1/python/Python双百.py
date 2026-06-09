用while循环先把那个没有len()的ListNode变成一个List，然后就能用 return List[-k]来解题。
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def kthToLast(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: int
        """
        list1 = []
        newhead = head
        while newhead.next != None:
            list1.append(newhead.val)
            newhead = newhead.next
        list1.append(newhead.val)
        #到这里， 就变成List啦！
        return list1[-k]
        
```
