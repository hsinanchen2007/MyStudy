### 解题思路
使用双指针，一个指针每次移动一个节点，另一个指针每次移动两个节点，如果存在环，那么这两个指针一定会相遇。
![image.png](https://pic.leetcode-cn.com/35a5d2b72f60dd13ccfb7a234439dc188fc4b8d87bf40a880ca8789c687386d9-image.png)

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
                return False
        l1 = head
        l2 = head.next
        while l1 != None and l2 != None and l2.next != None:
            if l1 == l2 :
                return True
            l1 = l1.next
            l2 = l2.next.next
        return False 
```
