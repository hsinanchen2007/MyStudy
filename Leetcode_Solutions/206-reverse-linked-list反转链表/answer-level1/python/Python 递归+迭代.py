### 解题思路


### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#迭代
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        now=head
        pre=None
        while now!=None:
            next_node=now.next
            now.next=pre
            pre=now
            now=next_node
        return pre
        

#递归
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None or head.next==None:
            return head
        next_node=head.next
        node=self.reverseList(next_node)
        next_node.next=head
        head.next=None
        
        return node


```

