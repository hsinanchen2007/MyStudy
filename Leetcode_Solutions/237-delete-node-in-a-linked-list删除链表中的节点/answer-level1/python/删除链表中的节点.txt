```
class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        if node == None:
            return node

        if node.next == None:
            node = None
             
        node.val = node.next.val
        node.next = node.next.next
```
