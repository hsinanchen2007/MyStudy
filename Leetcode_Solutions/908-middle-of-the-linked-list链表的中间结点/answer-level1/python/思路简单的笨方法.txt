### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        lens = 0
        p = head
        #先判断该链表的长度是奇数或者偶数
        while head:
            head = head.next
            lens += 1
        if lens % 2 == 0: #偶数
            for i in range(0, lens/2):
                p = p.next
            #p = p.next
            ans = p
        else: #奇数
            for i in range(0, int(lens/2)):
                p = p.next
            ans = p
        return ans

```