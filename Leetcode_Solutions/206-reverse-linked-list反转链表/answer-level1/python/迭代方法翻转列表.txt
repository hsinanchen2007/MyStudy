### 解题思路
每日打卡第二天，感觉这一题还是用迭代的方式容易想一点，感觉用递归容易绕不过来

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        prev = None
        while head != None:
            tmp = head.next
            head.next = prev
            prev = head
            head = tmp
        
        return prev
```