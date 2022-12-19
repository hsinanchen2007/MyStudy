### 解题思路
![image.png](https://pic.leetcode-cn.com/68f411aa7f1c780587bdde11f75c6d3bb264e178bfa70f2b14193a75a0c88c5d-image.png)

![image.png](https://pic.leetcode-cn.com/c78ecd228dde80f43d5aaec69b424ecc50e7b77c945232d64dceedb2309ca14c-image.png)


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

        if l1 == None:
            return l2
        elif l2 == None:
            return l1

        if l1.val <= l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        elif l1.val > l2.val:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2
```