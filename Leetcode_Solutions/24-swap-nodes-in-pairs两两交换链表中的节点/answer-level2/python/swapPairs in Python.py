```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # if the list is empty or has only one node.
        if not head or not head.next:
            return head
        
        # nodes need to be swapped
        first_node = head
        sec_node = head.next

        # swapping
        first_node.next = self.swapPairs(sec_node.next)
        sec_node.next = first_node

        return sec_node
```
