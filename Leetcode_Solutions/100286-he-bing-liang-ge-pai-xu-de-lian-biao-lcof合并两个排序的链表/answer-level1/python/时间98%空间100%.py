
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        node1, node2 = l1, l2
        rnode = None
        rnode_copy = None
        while(node1!=None and node2!=None):
            if rnode==None:
                if node1.val<node2.val:
                    rnode = node1
                    rnode_copy = rnode
                    node1 = node1.next
                else:
                    rnode = node2
                    rnode_copy = rnode
                    node2 = node2.next
            else:
                if node1.val<node2.val:
                    rnode.next = node1
                    rnode = rnode.next
                    node1 = node1.next
                else:
                    rnode.next = node2
                    rnode = rnode.next
                    node2 = node2.next
        while(node1!=None):
            if rnode==None:
                rnode = node1
                rnode_copy = rnode
                node1 = node1.next
            else:
                rnode.next = node1
                rnode = rnode.next
                node1 = node1.next
        while(node2!=None):
            if rnode==None:
                rnode = node2
                rnode_copy = rnode
                node2 = node2.next
            else:
                rnode.next = node2
                rnode = rnode.next
                node2 = node2.next
        return rnode_copy
                    
```