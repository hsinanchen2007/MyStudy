### 解题思路
执行用时 :20 ms, 在所有 Python 提交中击败了80.73%的用户
内存消耗 :
13 MB, 在所有 Python 提交中击败了5.37%的用户

遍历两次的方法 直观
### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        p = head
        length = 0
        while p.next:
            length += 1
            p = p.next  
        length += 1
        p = head
        if length - n == 0:
            if head.next:
                head = head.next
            else:
                head = None
        else:
            for i in range(length - n -1):
                p = p.next
            if p.next.next:
                p.next = p.next.next
            else:
                p.next = None

        return head  


```