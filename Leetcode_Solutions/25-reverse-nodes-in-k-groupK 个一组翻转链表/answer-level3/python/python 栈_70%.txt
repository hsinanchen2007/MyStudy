```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head :
            return head
        left=ListNode(None)
        res=left
        stack=[]
        right=head
        left.next=head
        while right or len(stack)>=k:
            # print stack
            if right and len(stack)<k:stack.append(right)
            else:
                while stack:
                    item=stack.pop()
                    if item:
                        left.next=item
                        left=left.next
                left.next=right
                if right:
                    stack.append(right)
            if right:
                right=right.next
        # print stack
        return res.next
```
