### 解题思路
创建一个新的ListNode节点，依次比较l1和l2的大小进行插入。

### 代码

```python
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
        front1 = l1

        front2 = l2

        L = ListNode(1)
        p = L
        while front1 and front2:
            if front1.val < front2.val:
                L.next = front1
                front1 = front1.next
                
            elif front1.val > front2.val:
                L.next = front2
                front2 = front2.next
                
            else:
                L.next = front1
                front1 = front1.next
                L = L.next
                L.next = front2
                front2 = front2.next
            L = L.next


        if front1:
            while front1:
                L.next = front1
                L = L.next
                front1 = front1.next
        if front2:           
            while front2:
                L.next = front2
                L = L.next
                front2 = front2.next
        return p.next

            
            





```