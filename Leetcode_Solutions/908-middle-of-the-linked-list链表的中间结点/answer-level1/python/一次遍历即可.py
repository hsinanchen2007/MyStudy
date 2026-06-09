### 解题思路
设置两个指针,一个是另一个速度的二分之一就可以

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
        quick = head
        slow = head
        cnt=0
        while quick!=None:
            quick = quick.next
            cnt+=1
            if cnt%2==0:
                slow = slow.next
        return slow
```